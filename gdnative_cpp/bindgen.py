from contextlib import contextmanager
import json

class Document:
	def __init__(self, parent: "Document", default_list):
		self.elements = default_list
		self.parent = parent

	def indent(self, str_builder: list) -> None:
		element = self.parent

		while (element):
			str_builder.append("\t")

			element = element.parent

class Root(Document):
	def __str__(self):
		return str().join(self.elements)

class Namespace(Document):
	pass

class Class(Document):
	pass

@contextmanager
def new_class(document: Document, class_name: str, base_name = "") -> Class:
	elements = []

	try:
		document.indent(elements)
		elements.append("class ")
		elements.append(class_name)

		if (base_name):
			elements.append(" : public ")
			elements.append(base_name)

		elements.append(" {\n")

		yield Class(document, elements)
	finally:
		document.indent(elements)
		elements.append("};\n")
		document.elements.append(str().join(elements))

def new_enum(document: Document, enum_name: str, values: dict):
	elements = []

	document.indent(elements)
	elements.append("enum ")

	if (len(enum_name) == 0):
		elements.append("{\n")
	else:
		elements.append(enum_name)
		elements.append(" {\n")

	for key, value in values.items():
		document.indent(elements)
		elements.append("\t")
		elements.append(key)
		elements.append(" = ")
		elements.append(str(value))
		elements.append(",\n")

	document.indent(elements)
	elements.append("};\n")
	document.elements.append(str().join(elements))

def new_line(document: Document, line = "") -> None:
	if (len(line) != 0):
		elements = []

		document.indent(elements)
		elements.append(line)
		elements.append("\n")

		document.elements.append(str().join(elements))
	else:
		document.elements.append("\n")

def new_pragma(document: Document, pragma: str) -> None:
	elements = document.elements

	elements.append("#")
	elements.append(pragma)
	elements.append("\n")

@contextmanager
def new_namespace(root: Root, name: str) -> Namespace:
	elements = []

	elements.append("namespace ")
	elements.append(name)
	elements.append(" {\n")

	try:
		yield Namespace(root, elements)
	finally:
		elements.append("};\n")
		root.elements.append(str().join(elements))

core_types = [
	"Object",
	"Vector2",
	"Vector3",
	"Quat",
	"Plane",
	"AABB",
	"Rect2",
	"Color",
	"Basis",
	"Transform",
	"Transform2D",
	"String",
	"Array",
	"Dictionary",
	"NodePath",
	"RID",
	"Variant",
	"Error",
	"PoolByteArray",
	"PoolIntArray",
	"PoolRealArray",
	"PoolStringArray",
	"PoolVector2Array",
	"PoolVector3Array",
	"PoolColorArray",
]

reserved_keywords = [
	"new",
	"char",
	"default",
	"class",
	"typename",
	"operator",
	"bool",
	"export",
	"short"
]

array_type_names = [
	"godot::core::Array",
	"godot::core::PoolByteArray",
	"godot::core::PoolIntArray",
	"godot::core::PoolRealArray",
	"godot::core::PoolStringArray",
	"godot::core::PoolVector2Array",
	"godot::core::PoolVector3Array",
	"godot::core::PoolColorArray",
]

def new_method_declaration(document: Document, method: dict) -> None:
	def parse_type(type_name: str) -> str:
		if (type_name in core_types):
			return ("godot::core::" + type_name)
		else:
			enum_prefix = "enum."

			if (type_name.startswith(enum_prefix)):
				return type_name[(type_name.find(enum_prefix) + len(enum_prefix)):]

		return type_name

	def parse_literal(type_name: str, literal: str) -> str:
		if (type_name == "bool"):
			return literal.lower()

		if ((type_name == "godot::core::Vector2") or (type_name == "godot::core::Vector3")):
			return (type_name + "::of" + literal)

		if (type_name == "godot::core::Color"):
			return (type_name + "::of(" + literal + ")")

		if (type_name == "godot::core::Rect2"):
			return (type_name + "::from_bounds" + literal)

		if ((type_name == "godot::core::Transform2D") or (type_name == "godot::core::Transform")):
			# TODO
			return (type_name + "::zero()")

		if (type_name == "godot::core::String"):
			return (type_name + "(\"" + literal + "\")")

		if (type_name in array_type_names):
			return (type_name + "()")

		if ((literal == "Null") or (literal == "[Object:null]")):
			return (type_name + "()")

		if (literal == "[RID]"):
			return "RID()"

		return literal

	def escape_keywords(text: str) -> str:
		return (text + "_") if (text in reserved_keywords) else text

	elements = []

	document.indent(elements)
	elements.append(parse_type(method["return_type"]))
	elements.append(" ")
	elements.append(escape_keywords(method["name"]))
	elements.append("(")

	arguments = method["arguments"]

	if (len(arguments) != 0):
		for argument in arguments:
			argument_type_name = argument["type"]

			elements.append(parse_type(argument_type_name))
			elements.append(" ")
			elements.append(escape_keywords(argument["name"]))

			if (argument["has_default_value"]):
				elements.append(" = ")

				elements.append(parse_literal(
					parse_type(argument_type_name),
					argument["default_value"])
				)

			elements.append(", ")

		elements.pop()

	elements.append(");\n")
	document.elements.append(str().join(elements))

document = Root(None, [])
api_file_path = "../godot_headers/api.json"
engine_header_file_path = "./godot/engine.hpp"

with open(api_file_path, "r") as api_file:
	api = json.load(api_file)

	new_pragma(document, "ifndef GODOT_ENGINE_H")
	new_pragma(document, "define GODOT_ENGINE_H")
	new_line(document)
	new_pragma(document, "include \"godot/core.hpp\"")
	new_line(document)

	with new_namespace(document, "godot::engine") as namespace:
		for godot_class in api:
			with new_class(namespace, godot_class["name"], godot_class["base_class"]) as class_:
				new_line(class_, "public:")

				constants = godot_class["constants"]

				if (len(constants) != 0):
					new_enum(class_, "", godot_class["constants"])

				for enum in godot_class["enums"]:
					new_enum(class_, enum["name"], enum["values"])

				for method in godot_class["methods"]:
					new_method_declaration(class_, method)


			new_line(namespace)

	new_line(document)
	new_pragma(document, "endif GODOT_ENGINE_H")

	with open(engine_header_file_path, "w") as engine_header_file:
		engine_header_file.write(str(document))
