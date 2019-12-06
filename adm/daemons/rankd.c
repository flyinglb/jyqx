// rankd.c
// 1996-02-15 dts ranking related to "shen"

#include <ansi.h>

string query_rank(object ob)
{
        mapping fam;

        int shen;
        int budd;
        int taoi;

        if( ob->is_ghost() )
                return HIB "��"+BLINK+" ��  �� "+NOR+HIB+"��" NOR;

        shen = ob->query("shen");
        if ( (fam = ob->query("family")) && fam["family_name"] == "������" )
                budd = ob->query_skill("buddhism",1);
        if ( (fam = ob->query("family")) && fam["family_name"] == "������" )
                budd = ob->query_skill("buddhism",1);
        if ( (fam = ob->query("family")) && fam["family_name"] == "����μ�" )
                budd = ob->query_skill("buddhism",1);
        if ( (fam = ob->query("family")) && fam["family_name"] == "�䵱��" )
                taoi = ob->query_skill("taoism",1);
        if ( (fam = ob->query("family")) && fam["family_name"] == "ȫ���" )
                taoi = ob->query_skill("taoism",1);

        switch(ob->query("gender")) {
        case "Ů��":
                switch(wizhood(ob)) {
                case "(superuser)":
                        return HIG "��"HBBLU+HIC"��������"NOR+HIG"��" NOR;
                case "(admin)":
                        return HIW "�� ��  �� ��" NOR;
                case "(arch)":
                        return HIR "�� ʥ  ĸ ��" NOR;
                case "(wizard)":
                        return HIY "�� ��  �� ��" NOR;
                case "(apprentice)":
                        return HIG "�� ��  Ů ��" NOR;
                case "(immortal)":
                        return HIC "�� ��  �� ��" NOR;
                default:
                        if( ((int)ob->query("PKS") > 30) )
				return HIG"��"+HIR+"Ůɱ��ħ"+HIG+"��" NOR;
//			else if (shen >= 500000)
//				return HIG "��"+HIC+"����Ů��"+HIG+"��" NOR;
//			else if (shen >= 50000)
//				return HIG "��"+HIC+" Ů���� "+HIG+"��" NOR;
//			else if (shen >= 5000)
//				return HIG "��"+HIC+" Ů  �� "+HIG+"��" NOR;
//			else if (shen >= 500)
//				return HIG "��"+HIC+" Ů���� "+HIG+"��" NOR;
//			else if (shen <= -500000)
//				return HIG "��"+HIM+"����Ůħ"+HIG+"��" NOR;
//			else if (shen <= -50000)
//				return HIG "��"+HIM+" Ů��ħ "+HIG+"��" NOR;
//			else if (shen <= -5000)
//				return HIG "��"+HIM+" Ů  ħ "+HIG+"��" NOR;
//			else if (shen <= -500)
//				return HIG "��"+HIM+" Ů��ħ "+HIG+"��" NOR;
			else if( (int)ob->query("thief") > 10 )
				return HIG"��"+HIM+"Ů �� ��"+HIG+"��"NOR;
			else
                        switch(ob->query("class")) {
                        case "bonze":
                                        if (budd >= 200)
                                                return HIW "��"+HIM+" ��  �� "+HIW+"��" NOR;
                                        else if (budd >= 150)
                                                return HIW "��"+HIM+" ʥ  �� "+HIW+"��" NOR;
                                        else if (budd >= 90)
                                                return HIW "��"+HIM+" ��  �� "+HIW+"��" NOR;
                                        else if (budd >= 60)
                                                return HIW "��"+HIM+" ʦ  ̫ "+HIW+"��" NOR;
                                        else if (budd >= 30)
                                                return HIW "��"+HIM+" ������ "+HIW+"��" NOR;
                                        else
                                                return CYN"��"+MAG+" ��  �� "+CYN+"��"NOR;
//				return CYN"��"+MAG+" ��  �� "+CYN+"��"NOR;
                        case "taoist":
                                        if (taoi >= 200)
                                                return HIW "��"+HIG+" ��  �� "+HIW+"��" NOR;
                                        else if (taoi >= 150)
                                                return HIW "��"+HIG+" ��  ʦ "+HIW+"��" NOR;
                                        else if (taoi >= 100)
                                                return HIW "��"+HIG+" Ů���� "+HIW+"��" NOR;
                                        else if (taoi >= 50)
                                                return HIW "��"+HIG+" ��  �� "+HIW+"��" NOR;
                                        else
                                                return CYN"��"+MAG+" Ů  �� "+CYN+"��"NOR;
//				return CYN"��"+MAG+" Ů  �� "+CYN+"��"NOR;
                        case "bandit":
                                return CYN"��"+MAG+" Ů���� "+CYN+"��"NOR;
                        case "dancer":
                                return CYN"��"+MAG+" ��  �� "+CYN+"��"NOR;
                        case "scholar":
                                return CYN"��"+MAG+" ��  Ů "+CYN+"��"NOR;
                        case "officer":
                                return CYN"��"+MAG+" Ů  �� "+CYN+"��"NOR;
                        case "fighter":
                                return CYN"��"+MAG+" Ů���� "+CYN+"��"NOR;
                        case "swordsman":
                                return CYN"��"+MAG+" Ů��ʿ "+CYN+"��"NOR;
                        case "alchemist":
                                return CYN"��"+MAG+" Ů��ʿ "+CYN+"��"NOR;
                        case "shaman":
                                return CYN"��"+MAG+" Ů��ҽ "+CYN+"��"NOR;
                        case "beggar":
                                return CYN"��"+MAG+"Ů�л���"+CYN+"��"NOR;
                        default:
                                return CYN"��"+MAG+" ƽ  �� "+CYN+"��"NOR;
                        }
                }
        default:
                switch(wizhood(ob)) {
                case "(superuser)":
                        return HIG "��"HBBLU+HIC"��Դ��ʿ"NOR+HIG"��" NOR;
                case "(admin)":
                        return HIW "�� ��  �� ��" NOR;
                case "(arch)":
                        return HIY "�� ʥ  ʦ ��" NOR;
                case "(wizard)":
                        return HIR "�� ��  �� ��" NOR;
                case "(apprentice)":
                        return HIG "�� ��  �� ��" NOR;
                case "(immortal)":
                        return HIC "�� ҹ  �� ��" NOR;
                default:
                        if( ((int)ob->query("PKS") > 30) )
				return HIG"��"+HIR+" ɱ��ħ "+HIG+"��"NOR;
//			else if (shen >= 500000)
//				return HIG "��"+HIC+"��������"+HIG+"��" NOR;
//			else if (shen >= 50000)
//				return HIG "��"+HIC+" ��  �� "+HIG+"��" NOR;
//			else if (shen >= 5000)
//				return HIG "��"+HIC+" ��  �� "+HIG+"��" NOR;
//			else if (shen >= 500)
//				return HIG "��"+HIC+" ��  �� "+HIG+"��" NOR;
//			else if (shen <= -500000)
//				return HIG "��"+HIW+" ħ  �� "+HIG+"��" NOR;
//			else if (shen <= -50000)
//				return HIG "��"+HIW+" ��  ħ "+HIG+"��" NOR;
//			else if (shen <= -5000)
//				return HIG "��"+HIW+" ħ  ͷ "+HIG+"��" NOR;
//			else if (shen <= -500)
//				return HIG "��"+HIW+" ��  ħ "+HIG+"��" NOR;
			else if( (int)ob->query("thief") > 10 )
				return HIG"��"+HIW+" ��  �� "+HIG+"��"NOR;
			else
                                switch(ob->query("class")) {
                                case "bonze":
                                        if (budd >= 200)
                                                return HIG "��"+HIY+" ��  ʦ "+HIG+"��" NOR;
                                        else if (budd >= 150)
                                                return HIG "��"+HIY+" ��  �� "+HIG+"��" NOR;
                                        else if (budd >= 120)
                                                return HIG "��"+HIY+" ʥ  ɮ "+HIG+"��" NOR;
                                        else if (budd >= 90)
                                                return HIG "��"+HIY+" ��  �� "+HIG+"��" NOR;
                                        else if (budd >= 60)
                                                return HIG "��"+HIY+" ��  �� "+HIG+"��" NOR;
                                        else if (budd >= 40)
                                                return HIG "��"+HIY+" ��  ʦ "+HIG+"��" NOR;
                                        else if (budd >= 30)
                                                return HIG "��"+HIY+" ��  �� "+HIG+"��" NOR;
                                        else
                                                return CYN"��"+WHT+" ɮ  �� "+CYN+"��"NOR;
                                case "taoist":
                                        if (taoi >= 200)
                                                return HIC "��"+HIG+" ��  �� "+HIC+"��" NOR;
                                        else if (taoi >= 150)
                                                return HIC "��"+HIG+" ��  ʦ "+HIC+"��" NOR;
                                        else if (taoi >= 100)
                                                return HIC "��"+HIG+" ��  �� "+HIC+"��" NOR;
                                        else if (taoi >= 50)
                                                return HIC "��"+HIG+" ��  �� "+HIC+"��" NOR;
                                        else
                                                return CYN"��"+WHT+" ��  ʿ "+CYN+"��"NOR;
//					return CYN"��"+WHT+" ��  ʿ "+CYN+"��"NOR;
                                case "bandit":
                                        return CYN"��"+WHT+" ��  �� "+CYN+"��"NOR;
                                case "scholar":
                                        return CYN"��"+WHT+" ��  �� "+CYN+"��"NOR;
                                case "officer":
                                        return CYN"��"+WHT+" ��  �� "+CYN+"��"NOR;
                                case "fighter":
                                        return CYN"��"+WHT+" ��  �� "+CYN+"��"NOR;
                                case "swordsman":
                                        return CYN"��"+WHT+" ��  ʿ "+CYN+"��"NOR;
                                case "alchemist":
                                        return CYN"��"+WHT+" ��  ʿ "+CYN+"��"NOR;
                                case "shaman":
                                        return CYN"��"+WHT+" ��  ҽ "+CYN+"��"NOR;
                                case "beggar":
                                        return CYN"��"+WHT+" �л��� "+CYN+"��"NOR;
                                default:
                                        return CYN"��"+WHT+" ƽ  �� "+CYN+"��"NOR;
                                }
                }
        }
}

string query_respect(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/respect")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ̫";
                                else return "ʦ̫";
                                break;
                        case "taoist":
                                if( age < 18 ) return "С�ɹ�";
                                else return "�ɹ�";
                                break;
                        default:
                                if( age < 18 ) return "С����";
                                else if( age < 50 ) return "����";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "Сʦ��";
                                else return "��ʦ";
                                break;
                        case "taoist":
                                if( age < 18 ) return "����";
                                else return "����";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "С�ϵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ǰ��";
                                break;
                        default:
                                if( age < 20 ) return "С�ֵ�";
                                else if( age < 50 ) return "׳ʿ";
                                else return "��ү��";
                                break;
                        }
        }
}

string query_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                return "����";
                                break;
                        case "taoist":
                                return "��Ů";
                                break;
                        default:
                                if( age < 30 ) return "С����";
                                else return "����̫��";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "��ͺ¿";
                                else return "��ͺ¿";
                                break;
                        case "taoist":
                                return "��ţ����";
                                break;
                        default:
                                if( age < 20 ) return "С���˵�";
                                if( age < 50 ) return "����";
                                else return "��ƥ��";
                                break;
                        }
        }
}

string query_self(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        default:
                                if( age < 30 ) return "СŮ��";
                                else return "���";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶɮ";
                                else return "����";
                                break;
                        case "taoist":
                                return "ƶ��";
                                break;
                        default:
                                if( age < 50 ) return "����";
                                else return "��ͷ��";
                                break;
                        }
        }
}

string query_self_rude(object ob)
{
        int age;
        string str;

        if( stringp(str = ob->query("rank_info/self_rude")) )
                return str;

        age = ob->query("age");
        switch(ob->query("gender")) {
                case "Ů��":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "ƶ��";
                                else return "����";
                                break;
                        default:
                                if( age < 30 ) return "������";
                                else return "����";
                                break;
                        }
                case "����":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "�������";
                                else return "�Ϻ�����";
                                break;
                        case "taoist":
                                return "��ɽ��";
                                break;
                        default:
                                if( age < 50 ) return "��ү��";
                                else return "����";
                                break;
                        }
        }
}
string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
        }
}

string query_self_close(object ob)
{
        int a1, a2;
        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
        }
        return "����rankd.c -> query_self_close()\n";
}
//=========================����Ϊ�����imud��emote���ܶ�����====================
string imud_query_self_close(object ob,int age,string gender)
{
        int a1, a2;
        if (objectp(ob))
        {
                a1=ob->query("age");
                a2=age;
        }
        else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }
        switch (gender) {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
        }
}

string imud_query_close(object ob,int age,string gender)
{
        int a1, a2;

        if (objectp(ob))
        {
                a1=ob->query("age");
                a2=age;
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (gender) {
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
        }
}
