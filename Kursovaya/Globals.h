#pragma once
#include <Windows.h>
#include <msclr\marshal_cppstd.h>

#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include "libs/json.hpp"

using namespace System::Globalization;
using namespace System::Drawing;
constexpr auto accountsFilename = "accounts.json";
constexpr auto settingsFilename = "settings.json";
constexpr auto mainDataFilename = "HairShopData.json";

namespace Languages
{
	constexpr std::string_view ENG = "en-US", RU = "ru-RU", BEL = "be-BY";
}


[[nodiscard]] std::string CaesarEncrypt(std::string_view str, size_t key);
[[nodiscard]] std::string CaesarDecrypt(std::string_view str, size_t key);

[[nodiscard]] std::string string_cast(System::String^ str);
[[nodiscard]] System::String^ string_cast(std::string str);


[[nodiscard]] inline int32_t RGBtoInt(uint8_t R, uint8_t G, uint8_t B) {
	constexpr uint8_t maxAlpha = 255;
	return ((maxAlpha << 24) | (R << 16) | (G << 8) | B);
}

namespace Themes
{
	enum: uint16_t {
		Light,
		Dark,
		Colorful,
		SIZE
	};

	class Theme {
	private:
		int fc, bc, tc;
	public:
		Theme(int fc, int bc, int tc)
			:fc{fc}, bc{bc}, tc{tc} {}

		[[nodiscard]] auto getForeColor() const {
			return Color::FromArgb(fc);
		}

		[[nodiscard]] auto getBackColor() const {
			return Color::FromArgb(bc);
		}

		[[nodiscard]] auto getThirdColor() const {
			return Color::FromArgb(tc);
		}
	};
}

ref struct GlobalObjects {
	static System::Resources::ResourceManager^ resources;
	static CultureInfo^ culture;
};

struct Globals {
	static inline uint16_t currentTheme;
	static inline nlohmann::json accsJson, mainDataJson, settingsJson;
	static inline const Themes::Theme themes[Themes::SIZE]{
		{RGBtoInt(200, 140, 140), RGBtoInt(245, 245, 245),RGBtoInt(135, 135, 160)},
		{RGBtoInt(221, 120, 153), RGBtoInt(19, 21, 23), RGBtoInt(88, 97, 116)},
		{RGBtoInt(199, 99, 126), RGBtoInt(49, 51, 66), RGBtoInt(209, 110, 142)}
	};

	static void init() {
		settingsJson["Language"] = Languages::ENG;
		settingsJson["Theme"] = Themes::Light;

		GlobalObjects::resources = gcnew System::Resources::ResourceManager(
			L"Kursovaya.Resource",
			System::Reflection::Assembly::GetExecutingAssembly()
		);

		if(std::ifstream a(accountsFilename); a.good())
			a >> accsJson;
		if(std::ifstream t(settingsFilename); t.good()) {
			t >> settingsJson;
			changeLang(settingsJson["Language"].get<std::string>());
		}
		settingsJson["Theme"].get_to(currentTheme);
	}

	static void changeLang(std::string_view language) {
		const auto L = string_cast(language.data());
		GlobalObjects::culture = gcnew CultureInfo(L);
		GlobalObjects::culture = CultureInfo::GetCultureInfo(L);
		CultureInfo::DefaultThreadCurrentCulture = GlobalObjects::culture;
		CultureInfo::DefaultThreadCurrentUICulture = GlobalObjects::culture;
		settingsJson["Language"] = language;
	}

	static void applyTheme(System::Windows::Forms::Form^ form) {
		using namespace System::Windows::Forms;
		const auto& theme = themes[currentTheme];

		form->BackColor = theme.getBackColor();
		for each(Control ^ control in form->Controls) {
			if(auto dgv = dynamic_cast<DataGridView^>(control); dgv) {
				dgv->BackgroundColor = theme.getThirdColor();
				dgv->ForeColor = theme.getForeColor();
				continue;
			}
			control->BackColor = theme.getBackColor();
			control->ForeColor = theme.getForeColor();
		}
	}

	static void setTheme(uint16_t c) {
		currentTheme = settingsJson["Theme"] = c;
		save();
	}

	[[nodiscard]] static auto findAcc(std::string_view login) {
		return accsJson.find(login) != accsJson.end() ? accsJson[login] : nlohmann::json{};
	}

	static inline void addAcc(std::string_view login, std::string_view name, std::string_view password) {
		auto& acc = accsJson[login];
		acc["Name"] = name;
		acc["Password"] = CaesarEncrypt(password, login.length());
	}

	static void save() {
		std::ofstream(accountsFilename, std::ios::trunc) << accsJson;
		std::ofstream(settingsFilename, std::ios::trunc) << settingsJson;
	}
};

extern std::string currentUsername;

#define RESGETSTRING(str) \
    GlobalObjects::resources->GetString(str)

#define MB_ERROR(text) \
    MessageBox::Show(RESGETSTRING(text), RESGETSTRING("MB_ERROR"), MessageBoxButtons::OK, MessageBoxIcon::Error)

#define MB_WARNING(text) \
    MessageBox::Show(RESGETSTRING(text), RESGETSTRING("MB_WARNING"), MessageBoxButtons::OK, MessageBoxIcon::Warning)