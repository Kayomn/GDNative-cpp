#include "godot/core.hpp"

namespace godot::core {
	String::String() {
		api_core->godot_string_new(&this->handle);
	}

	String::String(String const& that) {
		api_core->godot_string_new_copy((&this->handle), (&that.handle));
	}

	String::String(char const* pointer) {
		api_core->godot_string_new(&this->handle);
		api_core->godot_string_parse_utf8((&this->handle), pointer);
	}

	String::~String() {
		api_core->godot_string_destroy(&this->handle);
	}

	bool String::is_empty() const {
		return api_core->godot_string_empty(&this->handle);
	}

	int String::length() const {
		return api_core->godot_string_length(&this->handle);
	}
}
