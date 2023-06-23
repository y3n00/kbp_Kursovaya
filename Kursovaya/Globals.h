#pragma once
#include <Windows.h>
#include <msclr\marshal_cppstd.h>

#include <filesystem>
#include <fstream>
#include <string>
#include "libs/json.hpp"

using namespace System::Globalization;
using namespace System::Drawing;
constexpr auto accountsFilename = "accounts.json";
constexpr auto settingsFilename = "settings.json";
constexpr auto mainDataFilename = "HairShopData.json";

namespace Languages {
	const std::string ENG = "en-US", RU = "ru-RU", BEL = "be-BY";
};

#define RGBTOINT(R,G,B)\
	int32_t((255 << 24) | (R << 16) | (G << 8) | B)

namespace Themes {
	enum : uint16_t {
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
			:fc{ fc }, bc{ bc }, tc{ tc }
		{}
		inline auto getForeColor() { return Color::FromArgb(fc); }
		inline auto getBackColor() { return Color::FromArgb(bc); }
		inline auto getThirdColor() { return Color::FromArgb(tc); }
	};

}

ref struct GlobalObjects {
	static System::Resources::ResourceManager^ resources;
	static CultureInfo^ culture;
};

[[nodiscard]] std::string CaesarEncrypt(std::string_view str, int key);
[[nodiscard]] std::string CaesarDecrypt(std::string_view str, int key);

[[nodiscard]] std::string string_cast(System::String^ str);
[[nodiscard]] System::String^ string_cast(std::string str);

struct Globals {
	static uint16_t currentTheme;
	static inline nlohmann::json accsJson, mainDataJson, settingsJson;
	static inline Themes::Theme themes[Themes::SIZE]{
		{RGBTOINT(255, 199, 199), RGBTOINT(246, 246, 246),RGBTOINT(135, 133, 162)},
		{RGBTOINT(33, 33, 33), RGBTOINT(13, 115, 119), RGBTOINT(50, 50, 50)},
		{RGBTOINT(75, 66, 55), RGBTOINT(213, 160, 33), RGBTOINT(237, 231, 217)}
	};

	static void init() {
		settingsJson["Language"] = Languages::ENG;
		currentTheme = settingsJson["Theme"] = Themes::Light;

		GlobalObjects::resources = gcnew System::Resources::ResourceManager(
			L"Kursovaya.Resource",
			System::Reflection::Assembly::GetExecutingAssembly()
		);

		if (std::ifstream a(accountsFilename); a.good())
			a >> accsJson;
		if (std::ifstream t(settingsFilename); t.good())
			t >> settingsJson;

		changeLang(settingsJson["Language"].get<std::string>());
	}

	static void changeLang(std::string language) {
		const auto L = string_cast(language);
		GlobalObjects::culture = gcnew CultureInfo(L);
		GlobalObjects::culture = CultureInfo::GetCultureInfo(L);
		CultureInfo::DefaultThreadCurrentCulture = GlobalObjects::culture;
		CultureInfo::DefaultThreadCurrentUICulture = GlobalObjects::culture;
		settingsJson["Language"] = language;
	}

	static void changeTheme(uint16_t c, System::Windows::Forms::Form^ form) {
		using namespace System::Windows::Forms;
		currentTheme = settingsJson["Theme"] = c;
		auto& theme = themes[currentTheme];

		form->BackColor = theme.getBackColor();
		for each (Control ^ control in form->Controls) {
			if (auto dgv = dynamic_cast<DataGridView^>(control); dgv) {
				dgv->BackgroundColor = theme.getThirdColor();
				dgv->ForeColor = theme.getForeColor();
				continue;
			}
			control->BackColor = theme.getBackColor();
			control->ForeColor = theme.getForeColor();
		}
	}

	[[nodiscard]] static inline const nlohmann::json findAcc(std::string_view login) {
		return accsJson[login];
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

	static void saveData(std::string path) {
		path += mainDataFilename;
		std::ofstream(path, std::ios::trunc) << mainDataJson;
	}

	static void loadData(const std::string& path) {
		mainDataJson.clear();
		if (std::filesystem::exists(path))
			std::ifstream(path) >> mainDataJson;
	}
};

extern std::string currentUsername;

#define RESGETSTRING(str) \
    GlobalObjects::resources->GetString(str)

#define MB_ERROR(text) \
    MessageBox::Show(RESGETSTRING(text), RESGETSTRING("MB_ERROR"), MessageBoxButtons::OK, MessageBoxIcon::Error)

#define MB_WARNING(text) \
    MessageBox::Show(RESGETSTRING(text), RESGETSTRING("MB_WARNING"), MessageBoxButtons::OK, MessageBoxIcon::Warning)

#undef RGBTOINT