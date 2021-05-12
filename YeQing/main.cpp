#include <string>

using namespace std;

//电源
struct Power {
	bool m_power_flag;//电源标志位
	string m_power_id;//电源序号
	double m_power_voltage;//电源电压

	Power(bool flag, string id, double voltage) :
		m_power_flag(flag), m_power_id(id), m_power_voltage(voltage) {}
};

//定位开关
struct PoSwitch {
	bool m_poswitch_flag;//定位开关标志位
	string m_poswitch_id;//定位开关序号

	PoSwitch(bool flag, string id) :
		m_poswitch_flag(flag), m_poswitch_id(id) {}
};

//分闸开关
struct SgSwitch {
	bool m_sgswitch_flag;//分闸开关标志位
	string m_sgswitch_id;//分闸开关序号

	SgSwitch(bool flag, string id) :
		m_sgswitch_flag(flag), m_sgswitch_id(id) {}
};

//延时继电器
struct TimeDelay {
	bool m_timedelay_flag;//延时继电器标志位
	string m_timedelay_id;//延时继电器序号

	TimeDelay(bool flag, string id) :
		m_timedelay_flag(flag), m_timedelay_id(id) {}
};

//急停按钮
struct ScramButton {
	bool m_scrambutton_flag;//急停按钮标志位
	string m_scrambutton_id;//急停按钮序号

	ScramButton(bool flag, string id) :
		m_scrambutton_flag(flag), m_scrambutton_id(id) {}
};

//电磁铁
enum EM_type { general_EM = 0, quakeproof_EM = 1 };//电磁铁种类枚举，普通电磁铁=0，防震电磁铁=1
struct ElectroMagnet {
	int m_electromagnet_type;//电磁铁种类
	bool m_electromagnet_flag;//电磁铁标志位
	string m_electromagnet_id;//电磁铁序号

	ElectroMagnet(int type, bool flag, string id) :
		m_electromagnet_type(type), m_electromagnet_flag(flag), m_electromagnet_id(id) {}
};

//延时函数
void timedelay() {

}

void main() {
	
	/*Initialize*/
	Power Power_0(0, "Power0", 220.0);
	PoSwitch PoSwitch_0(0, "PoSwitch0");
	SgSwitch SgSwitch_0(0, "SgSwitch0");
	TimeDelay TimeDelay_0(0, "TimeDelay0");
	TimeDelay TimeDelay_1(0, "TimeDelay1");
	ScramButton ScramButton_0(1, "ScramButton0");
	ScramButton ScramButton_1(1, "ScramButton1");
	ElectroMagnet ElectroMagnet_0(general_EM, 0, "ElectroMagnet0");
	ElectroMagnet ElectroMagnet_1(quakeproof_EM, 0, "ElectroMagnet1");
	/*end*/

	/*dowhile*/
	while (Power_0.m_power_flag == 1) {

		//定位开关控制延时继电器0
		if (PoSwitch_0.m_poswitch_flag == 1) {
			timedelay();//延时
			TimeDelay_0.m_timedelay_flag = 1;
		}

		//分闸开关控制延时继电器1
		if (SgSwitch_0.m_sgswitch_flag == 1) {
			timedelay();//延时
			TimeDelay_1.m_timedelay_flag = 1;
		}

		//防震电磁铁控制
		if (PoSwitch_0.m_poswitch_flag == 1 && TimeDelay_0.m_timedelay_flag == 1 && ScramButton_0.m_scrambutton_flag != 0) {
			ElectroMagnet_0.m_electromagnet_flag = 1;
		}

		//电磁铁控制
		if (PoSwitch_0.m_poswitch_flag == 1 && TimeDelay_1.m_timedelay_flag == 1 && ScramButton_1.m_scrambutton_flag != 0) {
			ElectroMagnet_1.m_electromagnet_flag = 1;
		}
	}
	/*end*/
}