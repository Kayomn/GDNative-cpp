#ifndef GODOT_CORE_H
#define GODOT_CORE_H

#include <gdnative_api_struct.gen.h>
#include <cstdlib>
#include <cstdint>
#include <cmath>

namespace godot::core {
	extern "C" static godot_gdnative_core_api_struct * api_core;

	extern "C" static godot_gdnative_core_1_1_api_struct * api_core11;

	extern "C" static godot_gdnative_core_1_2_api_struct * api_core12;

	extern "C" static godot_gdnative_ext_nativescript_api_struct * api_nativescript;

	extern "C" static godot_gdnative_ext_nativescript_1_1_api_struct * api_nativescript11;

	using real_t = float;

	static constexpr real_t PI = 3.14159265358979323846;

	static constexpr real_t TAU = 6.2831853071795864769252867666;

	static constexpr real_t INF = INFINITY;

	enum class Error {
		OK = 0,
		FAILED = 1,
		ERR_UNAVAILABLE = 2,
		ERR_UNCONFIGURED = 3,
		ERR_UNAUTHORIZED = 4,
		ERR_PARAMETER_RANGE_ERROR = 5,
		ERR_OUT_OF_MEMORY = 6,
		ERR_FILE_NOT_FOUND = 7,
		ERR_FILE_BAD_DRIVE = 8,
		ERR_FILE_BAD_PATH = 9,
		ERR_FILE_NO_PERMISSION = 10,
		ERR_FILE_ALREADY_IN_USE = 11,
		ERR_FILE_CANT_OPEN = 12,
		ERR_FILE_CANT_WRITE = 13,
		ERR_FILE_CANT_READ = 14,
		ERR_FILE_UNRECOGNIZED = 15,
		ERR_FILE_CORRUPT = 16,
		ERR_FILE_MISSING_DEPENDENCIES = 17,
		ERR_FILE_EOF = 18,
		ERR_CANT_OPEN = 19,
		ERR_CANT_CREATE = 20,
		ERR_QUERY_FAILED = 21,
		ERR_ALREADY_IN_USE = 22,
		ERR_LOCKED = 23,
		ERR_TIMEOUT = 24,
		ERR_CANT_CONNECT = 25,
		ERR_CANT_RESOLVE = 26,
		ERR_CONNECTION_ERROR = 27,
		ERR_CANT_AQUIRE_RESOURCE = 28,
		ERR_CANT_FORK = 29,
		ERR_INVALID_DATA = 30,
		ERR_INVALID_PARAMETER = 31,
		ERR_ALREADY_EXISTS = 32,
		ERR_DOES_NOT_EXIST = 33,
		ERR_DATABASE_CANT_READ = 34,
		ERR_DATABASE_CANT_WRITE = 35,
		ERR_COMPILATION_FAILED = 36,
		ERR_METHOD_NOT_FOUND = 37,
		ERR_LINK_FAILED = 38,
		ERR_SCRIPT_FAILED = 39,
		ERR_CYCLIC_LINK = 40,
		ERR_INVALID_DECLARATION = 41,
		ERR_DUPLICATE_SYMBOL = 42,
		ERR_PARSE_ERROR = 43,
		ERR_BUSY = 44,
		ERR_SKIP = 45,
		ERR_HELP = 46,
		ERR_BUG = 47,
		ERR_PRINTER_ON_FIRE = 48, /// The parallel port printer is engulfed in flames.
	};

	real_t stepify(real_t s, real_t step);

	struct Basis;

	class String;

	struct Vector2 {
		real_t x, y;

		static constexpr Vector2 inf() {
			return Vector2{INF, INF};
		}

		static constexpr Vector2 left() {
			return Vector2{-1.f, 0};
		}

		static constexpr Vector2 right() {
			return Vector2{1.f, 0};
		}

		static constexpr Vector2 up() {
			return Vector2{0, 1.f};
		}

		static constexpr Vector2 down() {
			return Vector2{0, -1.f};
		}

		static constexpr Vector2 of(real_t const x, real_t const y) {
			return Vector2{x, y};
		}

		static constexpr Vector2 one() {
			return Vector2{1.f, 1.f};
		}

		static constexpr Vector2 zero() {
			return Vector2{0, 0};
		}

		constexpr Vector2 operator-() const {
			return Vector2{-this->x, -this->y};
		}

		constexpr Vector2 operator+(Vector2 const& that) const {
			return Vector2{(this->x + that.x), (this->y + that.y)};
		}

		constexpr Vector2 operator-(Vector2 const& that) const {
			return Vector2{(this->x - that.x), (this->y - that.y)};
		}

		constexpr Vector2 operator*(Vector2 const& that) const {
			return Vector2{(this->x * that.x), (this->y * that.y)};
		}

		constexpr Vector2 operator/(Vector2 const& that) const {
			return Vector2{(this->x / that.x), (this->y / that.y)};
		}

		constexpr Vector2 operator+(real_t const scalar) const {
			return Vector2{(this->x + scalar), (this->y + scalar)};
		}

		constexpr Vector2 operator-(real_t const scalar) const {
			return Vector2{(this->x - scalar), (this->y - scalar)};
		}

		constexpr Vector2 operator*(real_t const scalar) const {
			return Vector2{(this->x * scalar), (this->y * scalar)};
		}

		constexpr Vector2 operator/(real_t const scalar) const {
			return Vector2{(this->x / scalar), (this->y / scalar)};
		}

		constexpr bool operator==(Vector2 const& that) const {
			return ((this->x == that.x) && (this->y == that.y));
		}

		constexpr bool operator!=(Vector2 const& that) const {
			return ((this->x != that.x) || (this->y != that.y));
		}

		Vector2 abs() const;

		real_t angle() const;

		real_t angle_to(Vector2 const& to) const;

		real_t angle_to_point(Vector2 const& to) const;

		real_t aspect() const;

		Vector2 bounce(Vector2 const& n) const;

		Vector2 ceil() const;

		Vector2 clamped(real_t length) const;

		real_t cross(Vector2 const& with) const;

		Vector2 cubic_interpolate(
			Vector2 const& b,
			Vector2 const& pre_a,
			Vector2 const& post_b,
			real_t t
		) const;

		Vector2 direction_to(Vector2 const& b) const;

		real_t distance_squared_to(Vector2 const& to) const;

		real_t distance_to(Vector2 const& to) const;

		real_t dot(Vector2 const& with) const;

		Vector2 floor() const;

		bool is_normalized() const;

		real_t length() const;

		real_t length_squared() const;

		Vector2 linear_interpolate(Vector2 const& b, real_t t) const;

		Vector2 move_toward(Vector2 const& to, real_t delta) const;

		Vector2 normalized() const;

		Vector2 project(Vector2 const& b) const;

		Vector2 reflect(Vector2 const& n) const;

		Vector2 rotated(real_t const phi) const;

		Vector2 round() const;

		Vector2 slerp(Vector2 const& b, real_t t) const;

		Vector2 slide(Vector2 const& n) const;

		Vector2 snapped(Vector2 const& by) const;

		Vector2 tangent() const;
	};

	struct Vector3 {
		enum Axis {
			AXIS_X,
			AXIS_Y,
			AXIS_Z
		};

		real_t x, y, z;

		static constexpr Vector3 inf() {
			return Vector3{INF, INF, INF};
		}

		static constexpr Vector3 left() {
			return Vector3{-1.f, 0, 0};
		}

		static constexpr Vector3 right() {
			return Vector3{1.f, 0, 0};
		}

		static constexpr Vector3 up() {
			return Vector3{0, 1.f, 0};
		}

		static constexpr Vector3 down() {
			return Vector3{0, -1.f, 0};
		}

		static constexpr Vector3 forward() {
			return Vector3{0, 0, -1.f};
		}

		static constexpr Vector3 back() {
			return Vector3{0, 0, 1.f};
		}

		static constexpr Vector3 of(real_t const x, real_t const y, real_t const z) {
			return Vector3{x, y, z};
		}

		static constexpr Vector3 one() {
			return Vector3{1.f, 1.f, 1.f};
		}

		static constexpr Vector3 zero() {
			return Vector3{0, 0, 0};
		}

		constexpr Vector3 operator-() const {
			return Vector3{-this->x, -this->y, -this->z};
		}

		constexpr Vector3 operator+(Vector3 const& that) const {
			return Vector3{(this->x + that.x), (this->y + that.y), (this->z + that.z)};
		}

		constexpr Vector3 operator-(Vector3 const& that) const {
			return Vector3{(this->x - that.x), (this->y - that.y), (this->z - that.z)};
		}

		constexpr Vector3 operator*(Vector3 const& that) const {
			return Vector3{(this->x * that.x), (this->y * that.y), (this->z * that.z)};
		}

		constexpr Vector3 operator/(Vector3 const& that) const {
			return Vector3{(this->x / that.x), (this->y / that.y), (this->z / that.z)};
		}

		constexpr Vector3 operator+(real_t const scalar) const {
			return Vector3{(this->x + scalar), (this->y + scalar), (this->z + scalar)};
		}

		constexpr Vector3 operator-(real_t const scalar) const {
			return Vector3{(this->x - scalar), (this->y - scalar), (this->z - scalar)};
		}

		constexpr Vector3 operator*(real_t const scalar) const {
			return Vector3{(this->x * scalar), (this->y * scalar), (this->z * scalar)};
		}

		constexpr Vector3 operator/(real_t const scalar) const {
			return Vector3{(this->x / scalar), (this->y / scalar), (this->z / scalar)};
		}

		constexpr bool operator==(Vector3 const& that) const {
			return ((this->x == that.x) && (this->y == that.y) && (this->z == that.z));
		}

		constexpr bool operator!=(Vector3 const& that) const {
			return ((this->x != that.x) || (this->y != that.y) || (this->z != that.z));
		}

		Vector3 abs() const;

		real_t angle_to(Vector3 const& to) const;

		Vector3 bounce(Vector3 const& n) const;

		Vector3 ceil() const;

		Vector3 cross(Vector3 const& b) const;

		Vector3 cubic_interpolate(
			Vector3 const& b,
			Vector3 const& pre_a,
			Vector3 const& post_b,
			real_t t
		) const;

		Vector3 direction_to(Vector3 const& b) const;

		real_t distance_squared_to(Vector3 const& b) const;

		real_t distance_to(Vector3 const& b) const;

		real_t dot(Vector3 const& b) const;

		Vector3 floor() const;

		Vector3 inverse() const;

		bool is_normalized() const;

		real_t length() const;

		Vector3 linear_interpolate(Vector3 const& b, real_t t) const;

		Axis min_axis() const;

		Axis max_axis() const;

		Vector3 move_toward(Vector3 const& to, real_t delta) const;

		Vector3 normalized() const;

		Basis outer(Vector3 const& b) const;

		Vector3 project(Vector3 const& b) const;

		Vector3 reflect(Vector3 const& n) const;

		Vector3 rotated(Vector3 const& axis, real_t phi) const;

		Vector3 round() const;

		Vector3 sign() const;

		Vector3 slerp(Vector3 const& b, real_t t) const;

		Vector3 slide(Vector3 const& n) const;

		Vector3 snapped(Vector3 const& by) const;

		Basis to_diagonal_matrix() const;
	};

	struct Quat {
		real_t x, y, z, w;

		static Quat from_euler(Vector3 euler);

		static Quat from_axis(Vector3 axis, real_t angle);

		static constexpr Quat of(
			real_t const x,
			real_t const y,
			real_t const z,
			real_t const w
		) {
			return Quat{x, y, z, w};
		}

		static constexpr Quat zero() {
			return Quat{0, 0, 0, 0};
		}

		Quat cubic_slerp(Quat const& b, Quat const& pre_a, Quat const& post_b, real_t t) const;

		constexpr Quat operator-() const {
			return Quat{(-this->x), (-this->y), (-this->z), (-this->w)};
		}

		constexpr Quat operator+(Quat const& that) const {
			return Quat{
				(this->x + that.x),
				(this->y + that.y),
				(this->z + that.z),
				(this->w + that.w)
			};
		}

		constexpr Quat operator-(Quat const& that) const {
			return Quat{
				(this->x - that.x),
				(this->y - that.y),
				(this->z - that.z),
				(this->w - that.w)
			};
		}

		constexpr Quat operator*(Quat const& that) const {
			return Quat{
				(this->x * that.x),
				(this->y * that.y),
				(this->z * that.z),
				(this->w * that.w)
			};
		}

		constexpr Quat operator/(Quat const& that) const {
			return Quat{
				(this->x / that.x),
				(this->y / that.y),
				(this->z / that.z),
				(this->w / that.w)
			};
		}

		constexpr Quat operator+(real_t const scalar) const {
			return Quat{
				(this->x + scalar),
				(this->y + scalar),
				(this->z + scalar),
				(this->w + scalar)
			};
		}

		constexpr Quat operator-(real_t const scalar) const {
			return Quat{
				(this->x - scalar),
				(this->y - scalar),
				(this->z - scalar),
				(this->w - scalar)
			};
		}

		constexpr Quat operator*(real_t const scalar) const {
			return Quat{
				(this->x * scalar),
				(this->y * scalar),
				(this->z * scalar),
				(this->w * scalar)
			};
		}

		constexpr Quat operator/(real_t const scalar) const {
			return Quat{
				(this->x / scalar),
				(this->y / scalar),
				(this->z / scalar),
				(this->w / scalar)
			};
		}

		constexpr bool operator==(Quat const& that) const {
			return (
				(this->x == that.x) &&
				(this->y == that.y) &&
				(this->z == that.z) &&
				(this->w == that.w)
			);
		}

		constexpr bool operator!=(Quat const& that) const {
			return (
				(this->x != that.x) ||
				(this->y != that.y) ||
				(this->z != that.z) ||
				(this->w != that.w)
			);
		}

		real_t dot(Quat const& b) const;

		Vector3 get_euler() const;

		Quat inverse() const;

		bool is_normalized() const;

		real_t length() const;

		real_t length_squared() const;

		Quat normalized() const;

		void set_axis_angle(Vector3 const& axis, real_t angle);

		void set_euler(Vector3 const& euler);

		Quat slerp(Quat const& b, real_t t) const;

		Quat slerpni(Quat const& b, real_t t) const;

		Vector3 xform(Vector3 const& v) const;
	};

	struct Plane {
		Vector3 normal;

		real_t d;

		static constexpr Plane from_points(
			Vector3 const& v1,
			Vector3 const& v2,
			Vector3 const& v3
		) {
			Vector3 const normal = (v1 - v2).cross(v1 - v2).normalized();

			return Plane{normal, normal.dot(v1)};
		}

		static constexpr Plane of(Vector3 const& normal, real_t d) {
			return Plane{normal, d};
		}

		constexpr bool operator==(Plane const& that) const {
			return ((this->normal == that.normal) && (this->d == that.d));
		}

		constexpr bool operator!=(Plane const& that) const {
			return ((this->normal != that.normal) || (this->d != that.d));
		}

		Vector3 center() const;

		real_t distance_to(Vector3 const& point);

		Vector3 get_any_point() const;

		bool has_point() const;

		Vector3 intersect_3(Plane const& b, Plane const& c) const;

		Vector3 intersects_ray(Vector3 const& from, Vector3 const& dir) const;

		Vector3 intersects_segment(Vector3 const& begin, Vector3 const& end) const;

		bool is_point_over(Vector3 const& point) const;

		Plane normalized() const;

		Vector3 project(Vector3 const& point) const;
	};

	struct AABB {
		Vector3 position;

		Vector3 size;

		static constexpr AABB of(Vector3 const& position, Vector3 const& size) {
			return AABB{position, size};
		}

		constexpr bool operator==(AABB const& that) const {
			return ((this->position == that.position) && (this->size == that.size));
		}

		constexpr bool operator!=(AABB const& that) const {
			return ((this->position != that.position) || (this->size != that.size));
		}

		AABB abs() const;

		bool encloses(AABB const& p_aabb) const;

		AABB expand(Vector3 const& p_vector) const;

		real_t get_area() const;

		Vector3 get_endpoint(int const idx) const;

		Vector3 get_longest_axis() const;

		int get_longest_axis_index() const;

		real_t get_longest_axis_size() const;

		Vector3 get_shortest_axis() const;

		int get_shortest_axis_index() const;

		real_t get_shortest_axis_size() const;

		Vector3 get_support(Vector3 const& dir) const;

		AABB grow(real_t by) const;

		bool has_no_area() const;

		bool has_no_surface() const;

		bool has_point(Vector3 const& point) const;

		AABB intersection(AABB const& with) const;

		bool intersects(AABB const& with) const;

		bool intersects_plane(Plane const& p_plane) const;

		bool intersects_segment(Vector3 const& from, Vector3 const& to) const;

		AABB merge(AABB const& p_with) const;
	};

	struct Rect2 {
		Vector2 position;

		Vector2 size;

		static constexpr Rect2 from_bounds(
			real_t const x,
			real_t const y,
			real_t const width,
			real_t const height
		) {
			return Rect2{Vector2::of(x, y), Vector2::of(width, height)};
		}

		static constexpr Rect2 of(Vector2 const& position, Vector2 const& size) {
			return Rect2{position, size};
		}

		constexpr bool operator==(Rect2 const& that) const {
			return ((this->position == that.position) && (this->size == that.size));
		}

		constexpr bool operator!=(Rect2 const& that) const {
			return ((this->position != that.position) || (this->size != that.size));
		}

		Rect2 abs() const;

		Rect2 clip(Rect2 const& b) const;

		bool encloses(Rect2 const& b) const;

		Rect2 expand(Vector2 const& to) const;

		real_t get_area() const;

		Rect2 grow(real_t by) const;

		Rect2 grow_individual(real_t left, real_t top, real_t right, real_t bottom) const;

		Rect2 grow_margin(int32_t margin, real_t by) const;

		bool has_no_area() const;

		bool intersects(Rect2 const& b, bool include_borders) const;

		Rect2 merge(Rect2 const& b) const;
	};

	struct Color {
		real_t r, g, b, a;

		static inline Color from_hsv(real_t h, real_t s, real_t v, real_t a);

		static constexpr Color from_rgba(uint32_t const from) {
			return Color{
				(((from >> 24) & 255) / 255.f),
				(((from >> 16) & 255) / 255.f),
				(((from >> 8) & 255) / 255.f),
				((from & 255) / 255.f)
			};
		}

		static constexpr Color of(
			real_t const r,
			real_t const g,
			real_t const b,
			real_t const a = 1.0f
		) {
			return Color{r, g, b, a};
		}

		constexpr bool operator==(Color const& that) const {
			return (
				(this->r == that.r) &&
				(this->g == that.g) &&
				(this->b == that.b) &&
				(this->a == that.a)
			);
		}

		constexpr bool operator!=(Color const& that) const {
			return (
				(this->r != that.r) ||
				(this->g != that.g) ||
				(this->b != that.b) ||
				(this->a != that.a)
			);
		}

		Color blend(Color const& over) const;

		Color contrasted() const;

		Color darkened(real_t amount) const;

		real_t gray() const;

		Color inverted() const;

		Color lightened(real_t amount) const;

		Color linear_interpolate(Color const& b, real_t t) const;

		uint32_t to_abgr32() const;

		uint64_t to_abgr64() const;

		uint32_t to_argb32() const;

		uint64_t to_argb64() const;

		uint32_t to_rgba32() const;

		uint64_t to_rgba64() const;
	};

	struct Basis {
		Vector3 x;

		Vector3 y;

		Vector3 z;

		static constexpr Basis of(
			Vector3 const& x_axis,
			Vector3 const& y_axis,
			Vector3 const& z_axis
		) {
			return Basis{x_axis, y_axis, z_axis};
		}

		static constexpr Basis zero() {
			return Basis{Vector3::zero(), Vector3::zero(), Vector3::zero()};
		}

		real_t determinant() const;

		Vector3 get_euler() const;

		int get_orthogonal_index() const;

		Quat get_rotation_quat() const;

		Vector3 get_scale() const;

		Basis inverse() const;

		Basis orthonormalized() const;

		Basis rotated(Vector3 const& axis, real_t const phi) const;

		Basis scaled(Vector3 const& scale) const;

		Basis slerp(Basis const& b, real_t const t) const;

		real_t tdotx(Vector3 const& with) const;

		real_t tdoty(Vector3 const& with) const;

		real_t tdotz(Vector3 const& with) const;

		Basis transposed() const;

		Vector3 xform(Vector3 const& v) const;

		Vector3 xform_inv(Vector3 const& v) const;
	};

	struct Transform {
		Basis basis;

		Vector3 origin;

		static constexpr Transform of(Basis const& basis, Vector3 const& origin) {
			return Transform{basis, origin};
		}

		static constexpr Transform zero() {
			return Transform{Basis::zero(), Vector3::zero()};
		}

		Transform affine_inverse() const;

		Transform interpolate_with(Transform const& transform, real_t const weight) const;

		Transform inverse() const;

		Transform looking_at(Vector3 const& target, Vector3 const& up) const;

		Transform orthonormalized() const;

		Transform rotated(Vector3 const& axis, real_t const phi) const;

		Transform scaled(Vector3 const& scale) const;

		Transform translated(Vector3 const& offset) const;

		Transform xform(Vector3 const& v) const;

		Transform xform_inv(Vector3 const& v) const;

		Transform xform(Plane const& v) const;

		Transform xform_inv(Plane const& v) const;

		Transform xform(AABB const& v) const;

		Transform xform_inv(AABB const& v) const;
	};

	struct Transform2D {
		Vector2 x;

		Vector2 y;

		Vector2 origin;

		static Transform2D from_rotated_origin(
			real_t const rotation,
			Vector2 const& position
		);

		static constexpr Transform2D of(
			Vector2 const& x_axis,
			Vector2 const& y_axis,
			Vector2 const& origin
		) {
			return Transform2D{x_axis, y_axis, origin};
		}

		static constexpr Transform2D zero() {
			return Transform2D{Vector2::zero(), Vector2::zero(), Vector2::zero()};
		}

		Transform2D affine_inverse() const;

		Vector2 basis_xform(Vector2 const& v) const;

		Vector2 basis_xform_inv(Vector2 const& v) const;

		Vector2 get_origin() const;

		real_t get_rotation() const;

		Vector2 get_scale() const;

		Transform2D interpolate_with(Transform2D const& transform, real_t const weight) const;

		Transform2D inverse() const;

		Transform2D orthonormalized() const;

		Transform2D rotated(real_t const phi) const;

		Transform2D scaled(Vector2 const& scale) const;

		Transform2D translated(Vector2 const& offset) const;

		Transform2D xform(Vector2 const& v) const;

		Transform2D xform_inv(Vector2 const& v) const;

		Transform2D xform(Rect2 const& v) const;

		Transform2D xform_inv(Rect2 const& v) const;
	};

	template<typename Type> class GodotClass {
		protected:
		Type super;
	};

	class Object final {
		godot_object * handle;

		public:
		constexpr Object() : handle(nullptr) { }

		constexpr Object(void * obj) : handle(static_cast<godot_object *>(obj)) { }

		constexpr godot_object * handleof() {
			return this->handle;
		}

		constexpr godot_object const* handleof() const {
			return this->handle;
		}
	};

	class String final {
		godot_string handle;

		public:
		String();

		String(String const& that);

		String(char const* pointer);

		~String();

		constexpr godot_string * handleof() {
			return (&this->handle);
		}

		constexpr godot_string const* handleof() const {
			return (&this->handle);
		}

		bool is_empty() const;

		int length() const;
	};

	class PoolByteArray final {
		godot_pool_byte_array handle;
	};

	class PoolIntArray final {
		godot_pool_int_array handle;
	};

	class PoolRealArray final {
		godot_pool_real_array handle;
	};

	class PoolStringArray final {
		godot_pool_string_array handle;
	};

	class PoolVector2Array final {
		godot_pool_vector2_array handle;
	};

	class PoolVector3Array final {
		godot_pool_vector3_array handle;
	};

	class PoolColorArray final {
		godot_pool_color_array handle;
	};

	class Array final {
		godot_array handle;

		public:
		enum BSearchFlags {
			BSEARCH_NONE = 0,
			BSEARCH_BEFORE = 0x1
		};

		enum DuplicateFlags {
			DUPLICATE_NONE = 0,
			DUPLICATE_DEEP = 0x1
		};

		enum SliceFlags {
			DUPLICATE_NONE = 0,
			DUPLICATE_DEEP = 0x1
		};

		Array();

		Array(Array const& that);

		constexpr Array(godot_array const& raw) : handle(raw) { }

		~Array();

		void append(Variant const& value);

		Variant back() const;

		int bsearch(Variant const& value, BSearchFlags flags);

		int bsearch_custom(
			Variant const& value,
			Object obj,
			String const& func,
			BSearchFlags flags
		);

		void clear();

		int count(Variant const& value) const;

		Array duplicate(DuplicateFlags const flags) const;

		bool is_empty() const;

		void erase(Variant const& value);

		int find(Variant const& what, int from) const;

		int find_last(Variant const& value) const;

		Variant front() const;

		constexpr godot_array * handleof() {
			return (&this->handle);
		}

		constexpr godot_array const* handleof() const {
			return (&this->handle);
		}

		bool has(Variant const& value) const;

		int hash() const;

		void insert(int position, Variant const& value);

		void invert();

		Variant max() const;

		Variant min() const;

		Variant pop_back();

		Variant pop_front();

		void push_back(Variant const& value);

		void push_front(Variant const& value);

		void remove(int position);

		void resize(int size);

		int rfind(Variant const& what, int from) const;

		void shuffle();

		int size() const;

		Array slice(int begin, int end, int step, SliceFlags flags) const;

		void sort();

		void sort_custom(Object obj, String const& func);
	};

	class Dictionary final {
		godot_dictionary handle;

		public:
		enum DuplicateFlags {
			DUPLICATE_NONE = 0,
			DUPLICATE_DEEP = 0x1
		};

		Dictionary();

		Dictionary(Dictionary const& from);

		constexpr Dictionary(godot_dictionary const& raw) : handle(raw) { }

		~Dictionary();

		void clear();

		Dictionary duplicate(DuplicateFlags flags) const;

		constexpr godot_dictionary * handleof() {
			return (&this->handle);
		}

		constexpr godot_dictionary const* handleof() const {
			return (&this->handle);
		}

		bool erase(Variant const& key);

		Variant get(Variant const& key, Variant const& fallback) const;

		bool has(Variant const& key) const;

		int hash() const;

		Array keys() const;

		int size() const;

		Array values() const;
	};

	class NodePath final {
		godot_node_path handle;

		public:
		NodePath();

		NodePath(String const& from);

		NodePath(NodePath const& that);

		~NodePath();

		NodePath get_as_property_path() const;

		String get_concatenated_subnames() const;

		String get_name(int idx) const;

		int get_subname_count() const;

		bool is_absolute() const;

		bool is_empty() const;
	};

	class RID final {
		godot_rid handle;

		public:
		RID();

		RID(Object from);

		RID(RID const& that);

		~RID();

		int get_id() const;
	};

	class Variant {
		godot_variant handle;

		public:
		enum Type {
			TYPE_NIL = 0,
			TYPE_BOOL = 1,
			TYPE_INT = 2,
			TYPE_REAL = 3,
			TYPE_STRING = 4,
			TYPE_VECTOR2 = 5,
			TYPE_RECT2 = 6,
			TYPE_VECTOR3 = 7,
			TYPE_TRANSFORM2D = 8,
			TYPE_PLANE = 9,
			TYPE_QUAT = 10,
			TYPE_AABB = 11,
			TYPE_BASIS = 12,
			TYPE_TRANSFORM = 13,
			TYPE_COLOR = 14,
			TYPE_NODE_PATH = 15,
			TYPE_RID = 16,
			TYPE_OBJECT = 17,
			TYPE_DICTIONARY = 18,
			TYPE_ARRAY = 19,
			TYPE_POOL_RAW_ARRAY = 20,
			TYPE_POOL_INT_ARRAY = 21,
			TYPE_POOL_REAL_ARRAY  = 22,
			TYPE_POOL_STRING_ARRAY = 23,
			TYPE_POOL_VECTOR2_ARRAY = 24,
			TYPE_POOL_VECTOR3_ARRAY = 25,
			TYPE_POOL_COLOR_ARRAY = 26,
			TYPE_MAX = 27
		};

		enum Operator {
			// Comparison
			OP_EQUAL,
			OP_NOT_EQUAL,
			OP_LESS,
			OP_LESS_EQUAL,
			OP_GREATER,
			OP_GREATER_EQUAL,
			// Arithmetic
			OP_ADD,
			OP_SUBSTRACT,
			OP_MULTIPLY,
			OP_DIVIDE,
			OP_NEGATE,
			OP_POSITIVE,
			OP_MODULE,
			OP_STRING_CONCAT,
			// Bitwise
			OP_SHIFT_LEFT,
			OP_SHIFT_RIGHT,
			OP_BIT_AND,
			OP_BIT_OR,
			OP_BIT_XOR,
			OP_BIT_NEGATE,
			// Boolean logic
			OP_AND,
			OP_OR,
			OP_XOR,
			OP_NOT,
			// Containment
			OP_IN,
			OP_MAX
		};

		Variant();

		Variant(Variant const& that);

		constexpr Variant(godot_variant const& raw) : handle(raw) { }

		Variant(int64_t value);

		Variant(String const& value);

		Variant(Vector2 const& value);

		Variant(Rect2 const& value);

		Variant(Vector3 const& value);

		Variant(Plane const& value);

		Variant(AABB const& value);

		Variant(Quat const& value);

		Variant(Basis const& value);

		Variant(Transform2D const& value);

		Variant(Transform const& value);

		Variant(Color const& value);

		Variant(NodePath const& value);

		Variant(RID const& value);

		Variant(Object value);

		Variant(Dictionary const& value);

		Variant(Array const& value);

		Variant(PoolByteArray const& value);

		Variant(PoolIntArray const& value);

		Variant(PoolRealArray const& value);

		Variant(PoolStringArray const& value);

		Variant(PoolVector2Array const& value);

		Variant(PoolVector3Array const& value);

		Variant(PoolColorArray const& value);

		~Variant();

		Type type_of() const;

		Variant call(String const& method_name, Variant const** args, int const arg_count);

		constexpr godot_variant * handleof() {
			return (&this->handle);
		}

		constexpr godot_variant const* handleof() const {
			return (&this->handle);
		}

		bool has_method(String const& method_name) const;
	};
}

#endif
