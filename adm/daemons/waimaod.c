// waimaod.c ��ò

#include <ansi.h>

string query_waimao(string gender,int per)
{
	object obj=this_player();

	if ( gender == "����"||gender == "����" ) {
		switch(per)
		{
			case 39: return HIG"����������ˬ���Ǹ����棬�������ˡ�\n"NOR;
			case 38: return HIG"���ڷ����ʣ��������������������ٷ硣\n"NOR;
			case 37: return HIG"����Ʈ�ݳ������������ס�\n"NOR;
			case 36: return HIG"�����������񣬷�ױ����������������\n"NOR;
			case 35: return HIG"���ڷ�������Ŀ�����ǣ����˹�Ŀ������\n"NOR;
			case 34: return HIY"���ڷ����촽�����˿��Σ���ֹ�������ޡ�\n"NOR;
			case 33: return HIY"����˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ���\n"NOR;
			case 32: return HIY"���ھٶ���������ˮ�����̷��飬������������Ŀ�⡣\n"NOR;
			case 31: return HIY"����˫�۹⻪Ө��͸���������ǵĹ�â��\n"NOR;
			case 30: return HIY"����Ӣ���������������Ρ�\n"NOR;
			case 29: return MAG"����Ŀ�Ƶ��ᣬ�ߴ�ͦ���������Ķ���\n"NOR;
			case 28: return MAG"�����������£�����˹�ģ���ֹ�ʶȡ�\n"NOR;
			case 27: return MAG"���ý�ü��Ŀ��Ӣ�˲������Ǳ�����\n"NOR;
			case 26: return MAG"��������Ũ�ף����۱��ǣ��������ݣ������㵹��\n"NOR;
			case 25: return MAG"����ü��˫�����������ǣ�Ӣͦ���ڡ�\n"NOR;
			case 24: return CYN"���û���������׳��������Ӣ�˲�����\n"NOR;
			case 23: return CYN"���÷�ɫ��𪣬�촽ī����˹������\n"NOR;
			case 22: return CYN"����Ũü���ۣ��ߴ�ͦ�Σ�����������\n"NOR;
			case 21: return CYN"���ñ�ֱ�ڷ��������������Գ������Ը�\n"NOR;
			case 20: return CYN"����üĿ���㣬�����󷽣�һ���˲š�\n"NOR;
			case 19: return YEL"������Բ���������ڷ����Ǹ񲻷���\n"NOR;
			case 18: return YEL"������òƽƽ�������������ʲôӡ�ࡣ\n"NOR;
			case 17: return YEL"���ð����Բ���������⣬���ζ��ࡣ\n"NOR;
			case 16: return YEL"�����ͷ���룬����һ���Ͳ����øС�\n"NOR;
			case 15: return YEL"����������ݣ�����ݹǣ�����Ҫ�����Ρ�\n"NOR;
			case 14: return RED"���÷�ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц��\n"NOR;
			case 13: return RED"������ü���ۣ�������ߣ�������״��\n"NOR;
			case 12: return RED"���������Ƥ��ͷ���������˲����ٿ��ڶ��ۡ�\n"NOR;
			case 11: return RED"�����������죬������ף�����ޱȡ�\n"NOR;
			default:
				if (per <= 10 ) return RED"����ü����б����ͷѢ�ţ�����������\n"NOR;
				if (per >= 40 ) return HIW"����һ���������ȣ��ɷ���ǣ���ֹ������\n"NOR;
		}
	}
	if ( gender == "Ů��"){
		switch(per)
		{
			case 39: return HIG"�����������ɣ���մһ˿�̳���\n"NOR;
			case 38: return HIG"���ڲ�����ϼ���������񣬻����������ӡ�\n"NOR;
			case 37: return HIG"�����������������Ż���ɽ�����˼�֮���ס�\n"NOR;
			case 36: return HIG"���ڷ����۰ף�Ӥ��С�ڣ�üĿ���飬�·�̫�����١�\n"NOR;
			case 35: return HIG"�����������ģ����ȷ�����������Σ��۹�֬�ޡ�\n"NOR;
			case 34: return HIY"�����������ã�ü��ī���������Ұ꣬Ŀ���ﲨ��\n"NOR;
			case 33: return HIY"���ڷ�����ü�����溬�����������ݣ�ת�ζ��顣\n"NOR;
			case 32: return HIY"����üĿ�续������ʤѩ�����ν�����߻���\n"NOR;
			case 31: return HIY"���ڽ����������������£�����ܳ������㡣��\n"NOR;
			case 30: return HIY"�����о���毻���ˮ���ж����������磬��̬��ǧ��\n"NOR;
			case 29: return MAG"���ý�С���磬��������������������ˡ�\n"NOR;
			case 28: return MAG"����Ѽ��������������ü���ڷ����٣��������֡�\n"NOR;
			case 27: return MAG"��������ϸ����������������Ķ��ˣ�������ɡ�\n"NOR;
			case 26: return MAG"���÷���ϸ������欶��ˣ�����һ�����������ѡ�\n";
			case 25: return MAG"���÷��۰���������ҩ���̣����￴����\n"NOR;
			case 24: return CYN"������������Ŀ����ˮ��ǧ�����ġ�\n"NOR;
			case 23: return CYN"�����������ģ�����Ө͸��������˼��\n"NOR;
			case 22: return CYN"������Ц��Ȼ����Լ���ˡ�\n"NOR;
			case 21: return CYN"�������滨��¶������������\n"NOR;
			case 20: return CYN"���÷��˳������������ˡ�\n"NOR;
			case 19: return YEL"���ü���΢�ᣬ�ŵ��������¿��ˡ�\n"NOR;
			case 18: return YEL"�����䲻���£���Ҳ�׾�����Щ����֮����\n"NOR;
			case 17: return YEL"���������С�������޹⣬��������\n"NOR;
			case 16: return YEL"���øɻƿ��ݣ���ɫ���ƣ�����Ů��ζ��\n"NOR;
			case 15: return YEL"�����������Ƥɫ�ֺڣ���ª������\n"NOR;
			case 14: return RED"����һ�����������һ����û�øС�\n"NOR;
			case 13: return RED"������С�綹��üëϡ�裬�����צ������������\n"NOR;
			case 12: return RED"���ð���ü�������ۣ���Ƥ�Ʒ�������һ�������¡�\n"NOR;
			case 11: return RED"�������б�ۣ���ɫ�Ұܣ�ֱ����һ�㡣\n"NOR;
			default:
				if (per >= 40) return HIW"�������������ܣ������ƻã��Ѳ����Ƿ�������\n"NOR;
				if (per <= 10) return RED"���ó������Σ�״��ҹ�棬Ů�˳������������������硣\n"NOR;
		}
	}
}
