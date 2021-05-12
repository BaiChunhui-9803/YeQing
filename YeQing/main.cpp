#include <string>

using namespace std;

//��Դ
struct Power {
	bool m_power_flag;//��Դ��־λ
	string m_power_id;//��Դ���
	double m_power_voltage;//��Դ��ѹ

	Power(bool flag, string id, double voltage) :
		m_power_flag(flag), m_power_id(id), m_power_voltage(voltage) {}
};

//��λ����
struct PoSwitch {
	bool m_poswitch_flag;//��λ���ر�־λ
	string m_poswitch_id;//��λ�������

	PoSwitch(bool flag, string id) :
		m_poswitch_flag(flag), m_poswitch_id(id) {}
};

//��բ����
struct SgSwitch {
	bool m_sgswitch_flag;//��բ���ر�־λ
	string m_sgswitch_id;//��բ�������

	SgSwitch(bool flag, string id) :
		m_sgswitch_flag(flag), m_sgswitch_id(id) {}
};

//��ʱ�̵���
struct TimeDelay {
	bool m_timedelay_flag;//��ʱ�̵�����־λ
	string m_timedelay_id;//��ʱ�̵������

	TimeDelay(bool flag, string id) :
		m_timedelay_flag(flag), m_timedelay_id(id) {}
};

//��ͣ��ť
struct ScramButton {
	bool m_scrambutton_flag;//��ͣ��ť��־λ
	string m_scrambutton_id;//��ͣ��ť���

	ScramButton(bool flag, string id) :
		m_scrambutton_flag(flag), m_scrambutton_id(id) {}
};

//�����
enum EM_type { general_EM = 0, quakeproof_EM = 1 };//���������ö�٣���ͨ�����=0����������=1
struct ElectroMagnet {
	int m_electromagnet_type;//���������
	bool m_electromagnet_flag;//�������־λ
	string m_electromagnet_id;//��������

	ElectroMagnet(int type, bool flag, string id) :
		m_electromagnet_type(type), m_electromagnet_flag(flag), m_electromagnet_id(id) {}
};

//��ʱ����
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

		//��λ���ؿ�����ʱ�̵���0
		if (PoSwitch_0.m_poswitch_flag == 1) {
			timedelay();//��ʱ
			TimeDelay_0.m_timedelay_flag = 1;
		}

		//��բ���ؿ�����ʱ�̵���1
		if (SgSwitch_0.m_sgswitch_flag == 1) {
			timedelay();//��ʱ
			TimeDelay_1.m_timedelay_flag = 1;
		}

		//������������
		if (PoSwitch_0.m_poswitch_flag == 1 && TimeDelay_0.m_timedelay_flag == 1 && ScramButton_0.m_scrambutton_flag != 0) {
			ElectroMagnet_0.m_electromagnet_flag = 1;
		}

		//���������
		if (PoSwitch_0.m_poswitch_flag == 1 && TimeDelay_1.m_timedelay_flag == 1 && ScramButton_1.m_scrambutton_flag != 0) {
			ElectroMagnet_1.m_electromagnet_flag = 1;
		}
	}
	/*end*/
}