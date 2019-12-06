#include <ansi.h>
/*  ����Ӧ��perform����ϣ�
   #include "/kungfu/skill/eff_msg.h";
   int p;
    p = (int)target->query("qi")*100/(int)target->query("max_qi");
    msg += damage_msg(damage, "����");
    msg += "( $n"+eff_status_msg(p)+" )\n";     
*/

string eff_status_msg(int ratio)
{
        if( ratio>=100 ) return HIG "����������������һ��Ҳ���ۡ�" NOR;
        if( ratio > 90 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
        if( ratio > 80 ) return HIY "������������Щ���ˡ�" NOR;
        if( ratio > 75 ) return HIY "�������������˵����ˡ�" NOR;
        if( ratio > 70 ) return HIY "�����ƺ���ʼ�е㲻̫��⣬������Ȼ�������ɡ�" NOR;
        if( ratio > 65 ) return HIY "���˼����ˣ������ƺ��������¡�" NOR;
        if( ratio > 60 ) return HIY "���˲��ᣬ������״������̫�á�" NOR;
        if( ratio > 50 ) return HIY "�������꣬������״������̫�á�" NOR;
        if( ratio > 45 ) return HIR "��Ϣ���أ�������ʼɢ�ң��������ܵ�����ʵ���ᡣ" NOR;
        if( ratio > 40 ) return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˡ�" NOR;
        if( ratio > 35 ) return HIR "�Ѿ��˺����ۣ���������֧���Ų�����ȥ��" NOR;
        if( ratio > 30 ) return HIR "�Ѿ�һ��ͷ�ؽ����ģ������������֧���Ų�����ȥ��" NOR;
        if( ratio > 25 ) return HIR "�����൱�ص��ˣ�ֻ�»�������Σ�ա�" NOR;
        if( ratio > 20 ) return HIR "�������Ѿ����������ˡ�" NOR;
        if( ratio > 15 ) return RED "����֮���Ѿ�����֧�ţ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб��վ��վ���ȣ��ۿ���Ҫ���ڵ��ϡ�" NOR;
        if( ratio > 5  ) return RED "���˹��أ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
        if( ratio > 0  ) return RED "�Ѿ���������״̬����ʱ������ˤ����ȥ��" NOR;        
        return RED "���˹��أ��Ѿ�������в�����ʱ�����ܶ�����" NOR;
}

string damage_msg(int damage, string type)
{
        string str;

        if( damage == 0 ) return "���û������κ��˺���\n";

        switch( type ) {   
        case "����":
	case "����":
		if( damage < 10 ) return "���ֻ������ػ���$p��Ƥ�⡣\n";
		if( damage < 50 ) return "�����$p$l����һ��ϸ����Ѫ�ۡ�\n";
		if( damage < 100 ) return "������͡���һ������$n���ϻ���һ���˿ڣ�\n";
		if( damage < 170 ) return "������͡���һ������$n���ϻ���һ��Ѫ���ܵ��˿ڣ�\n";
		if( damage < 280 ) return "������͡���һ������$n���ϻ���һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
		return "���ֻ����$nһ���Һ���$w����$p$l����һ������ǵĿ����˿ڣ���\n";
                break;
	case "����":
		if( damage < 10 ) return "���ֻ������ش���$n��Ƥ�⡣\n";
		if( damage < 50 ) return "�����$n$l�̳�һ�����ڡ�\n";
		if( damage < 100 ) return "������ۡ���һ��������$n$l����\n";
		if( damage < 170 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
		if( damage < 280 ) return "��������͡���һ����$w����$n$l�̳�һ��Ѫ��ģ����Ѫ������\n";
		return "���ֻ����$nһ���Һ���$w����$p��$l�Դ���������Ѫ�������أ���\n";
                break;
        case "����":
		if( damage < 20 ) return "���ֻ���������ײ����$nһ�£�û�����ʲô�˺���\n";
		if( damage < 60 ) return "���$wֻ��$n��$l�ҳ�һ�����졣\n";
		if( damage < 120 ) return "�����ž����һ����$w����$n��$l����ʱ����һ���ϸߣ�\n";
		if( damage < 240 ) return "���$w���صû���$n��$l�����$p�������������ۡ����³�һ�����Ѫ��\n";
		if( damage < 380 ) return "���ֻ�������𡹵�һ�����죬$w����$n���ϣ���$p��һ�����ݰ���ɳ�ȥ��\n";
		return "ֻ��$w���ص�ײ����$n�����ϣ������������У�$p��ɢ�˼��Ƶ�̱����ȥ����\n";
                break;
        case "����":
                if( damage < 10 ) return "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
                if( damage < 20 ) return "�����$p��$l���һ�����ࡣ\n";
                if( damage < 40 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
                if( damage < 80 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
                if( damage < 120 ) return "������项��һ����$n����������\n";
                if( damage < 200 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
                if( damage < 300 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                if( damage < 400 ) return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
                return "ֻ����$nһ���ҽУ���������������ߵķ���һ�����˳�ȥ����\n";
                break;
        case "����":
                if( damage < 10 ) return "���ֻ�ǰ�$n������˰벽����������\n";
                if( damage < 20 ) return "���$nʹ��һ������$p��$l���һ�����ˡ�\n";
                if( damage < 50 ) return "���һ�����У���$n���ʹ��������ȥ��\n";
                if( damage < 100 ) return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n";
                if( damage < 200 ) return "���$n��ɫһ�±�òҰף��������������˺ü�����\n";
                if( damage < 300 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
                if( damage < 400 ) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n";
                return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
                break;   
        case "����":                
                if( damage < 100 ) return "���$n�ܵ�$N�����������ƺ�һ����\n";
                if( damage < 200 ) return "���$n��$N���������𣬡��١���һ������������\n";
                if( damage < 300 ) return "���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n";
                return "���$n��$N������һ����ǰһ�ڣ��������ɳ�������\n";
                break;   
        case "ץ��":     
                if( damage < 10 ) return "���ֻ����$n$l������ι���û��ʲô�˺���\n";
                if( damage < 25 ) return "���$n������ü��$p��$l�Ѿ���������һ��ǳǳ��Ѫ�ۡ�\n";
                if( damage < 50 ) return "���������$n$l��һ��Ƥ�⣬�۵�$p�����ۡ��ֽ���������\n";
                if( damage < 100 ) return "�����ৡ���һ����$n��$l�϶�ʱ��ץ�����Ѫ�ۣ���Ѫ���˳�����\n";
                if( damage < 200 ) return "���$n�۵ô��һ����$p$l�ϱ�ץ���˼��������Ѫ������Ѫֱ����\n";
                if( damage < 300 ) return "���ֻ����$nһ���Һ���$N����ץ����$p��$l���̳������Ѫ��ģ���Ŀ�����\n";
                if( damage < 400 ) return "�����������һ���ҽУ�$n����$p����$Nץ����һ��ƬƤ�⣬��Ѫ������أ���\n";
                return "���������$nһ����ҵĺ��У�ֱ͸$p$l������Ƥ���⳶��һ��飬¶����Ѫ���ܵĹ�ͷ����\n";
                break;       
        default:
                if( !type ) type = "�˺�";
                str =  "�����ɷǳ����µ�����";
                if( damage < 230 ) str = "�����ɼ������ص�";
                if( damage < 170 ) str = "������ʮ�����ص�";
                if( damage < 120 ) str = "�������൱���ص�";
                if( damage < 80 ) str = "��������Ϊ���ص�";
                if( damage < 50 ) str = "������һ������";
                if( damage < 30 ) str = "������һ��";
                if( damage < 20 ) str = "��������΢��";
                if( damage < 10 ) str =  "���ֻ����ǿ���һ����΢";
                return str + type + "��\n";
        }
}
