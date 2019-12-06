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
                return HIB "【"+BLINK+" 鬼  魂 "+NOR+HIB+"】" NOR;

        shen = ob->query("shen");
        if ( (fam = ob->query("family")) && fam["family_name"] == "少林派" )
                budd = ob->query_skill("buddhism",1);
        if ( (fam = ob->query("family")) && fam["family_name"] == "峨嵋派" )
                budd = ob->query_skill("buddhism",1);
        if ( (fam = ob->query("family")) && fam["family_name"] == "大理段家" )
                budd = ob->query_skill("buddhism",1);
        if ( (fam = ob->query("family")) && fam["family_name"] == "武当派" )
                taoi = ob->query_skill("taoism",1);
        if ( (fam = ob->query("family")) && fam["family_name"] == "全真教" )
                taoi = ob->query_skill("taoism",1);

        switch(ob->query("gender")) {
        case "女性":
                switch(wizhood(ob)) {
                case "(superuser)":
                        return HIG "【"HBBLU+HIC"化外真仙"NOR+HIG"】" NOR;
                case "(admin)":
                        return HIW "【 天  后 】" NOR;
                case "(arch)":
                        return HIR "【 圣  母 】" NOR;
                case "(wizard)":
                        return HIY "【 仙  子 】" NOR;
                case "(apprentice)":
                        return HIG "【 神  女 】" NOR;
                case "(immortal)":
                        return HIC "【 精  灵 】" NOR;
                default:
                        if( ((int)ob->query("PKS") > 30) )
				return HIG"【"+HIR+"女杀人魔"+HIG+"】" NOR;
//			else if (shen >= 500000)
//				return HIG "【"+HIC+"旷世女侠"+HIG+"】" NOR;
//			else if (shen >= 50000)
//				return HIG "【"+HIC+" 女大侠 "+HIG+"】" NOR;
//			else if (shen >= 5000)
//				return HIG "【"+HIC+" 女  侠 "+HIG+"】" NOR;
//			else if (shen >= 500)
//				return HIG "【"+HIC+" 女少侠 "+HIG+"】" NOR;
//			else if (shen <= -500000)
//				return HIG "【"+HIM+"灭世女魔"+HIG+"】" NOR;
//			else if (shen <= -50000)
//				return HIG "【"+HIM+" 女大魔 "+HIG+"】" NOR;
//			else if (shen <= -5000)
//				return HIG "【"+HIM+" 女  魔 "+HIG+"】" NOR;
//			else if (shen <= -500)
//				return HIG "【"+HIM+" 女少魔 "+HIG+"】" NOR;
			else if( (int)ob->query("thief") > 10 )
				return HIG"【"+HIM+"女 惯 窃"+HIG+"】"NOR;
			else
                        switch(ob->query("class")) {
                        case "bonze":
                                        if (budd >= 200)
                                                return HIW "【"+HIM+" 菩  萨 "+HIW+"】" NOR;
                                        else if (budd >= 150)
                                                return HIW "【"+HIM+" 圣  尼 "+HIW+"】" NOR;
                                        else if (budd >= 90)
                                                return HIW "【"+HIM+" 神  尼 "+HIW+"】" NOR;
                                        else if (budd >= 60)
                                                return HIW "【"+HIM+" 师  太 "+HIW+"】" NOR;
                                        else if (budd >= 30)
                                                return HIW "【"+HIM+" 比丘尼 "+HIW+"】" NOR;
                                        else
                                                return CYN"【"+MAG+" 尼  姑 "+CYN+"】"NOR;
//				return CYN"【"+MAG+" 尼  姑 "+CYN+"】"NOR;
                        case "taoist":
                                        if (taoi >= 200)
                                                return HIW "【"+HIG+" 真  仙 "+HIW+"】" NOR;
                                        else if (taoi >= 150)
                                                return HIW "【"+HIG+" 仙  师 "+HIW+"】" NOR;
                                        else if (taoi >= 100)
                                                return HIW "【"+HIG+" 女道长 "+HIW+"】" NOR;
                                        else if (taoi >= 50)
                                                return HIW "【"+HIG+" 道  姑 "+HIW+"】" NOR;
                                        else
                                                return CYN"【"+MAG+" 女  冠 "+CYN+"】"NOR;
//				return CYN"【"+MAG+" 女  冠 "+CYN+"】"NOR;
                        case "bandit":
                                return CYN"【"+MAG+" 女飞贼 "+CYN+"】"NOR;
                        case "dancer":
                                return CYN"【"+MAG+" 舞  妓 "+CYN+"】"NOR;
                        case "scholar":
                                return CYN"【"+MAG+" 才  女 "+CYN+"】"NOR;
                        case "officer":
                                return CYN"【"+MAG+" 女  官 "+CYN+"】"NOR;
                        case "fighter":
                                return CYN"【"+MAG+" 女武者 "+CYN+"】"NOR;
                        case "swordsman":
                                return CYN"【"+MAG+" 女剑士 "+CYN+"】"NOR;
                        case "alchemist":
                                return CYN"【"+MAG+" 女方士 "+CYN+"】"NOR;
                        case "shaman":
                                return CYN"【"+MAG+" 女巫医 "+CYN+"】"NOR;
                        case "beggar":
                                return CYN"【"+MAG+"女叫化子"+CYN+"】"NOR;
                        default:
                                return CYN"【"+MAG+" 平  民 "+CYN+"】"NOR;
                        }
                }
        default:
                switch(wizhood(ob)) {
                case "(superuser)":
                        return HIG "【"HBBLU+HIC"桃源隐士"NOR+HIG"】" NOR;
                case "(admin)":
                        return HIW "【 天  帝 】" NOR;
                case "(arch)":
                        return HIY "【 圣  师 】" NOR;
                case "(wizard)":
                        return HIR "【 仙  客 】" NOR;
                case "(apprentice)":
                        return HIG "【 神  人 】" NOR;
                case "(immortal)":
                        return HIC "【 夜  叉 】" NOR;
                default:
                        if( ((int)ob->query("PKS") > 30) )
				return HIG"【"+HIR+" 杀人魔 "+HIG+"】"NOR;
//			else if (shen >= 500000)
//				return HIG "【"+HIC+"旷世大侠"+HIG+"】" NOR;
//			else if (shen >= 50000)
//				return HIG "【"+HIC+" 大  侠 "+HIG+"】" NOR;
//			else if (shen >= 5000)
//				return HIG "【"+HIC+" 侠  客 "+HIG+"】" NOR;
//			else if (shen >= 500)
//				return HIG "【"+HIC+" 少  侠 "+HIG+"】" NOR;
//			else if (shen <= -500000)
//				return HIG "【"+HIW+" 魔  王 "+HIG+"】" NOR;
//			else if (shen <= -50000)
//				return HIG "【"+HIW+" 大  魔 "+HIG+"】" NOR;
//			else if (shen <= -5000)
//				return HIG "【"+HIW+" 魔  头 "+HIG+"】" NOR;
//			else if (shen <= -500)
//				return HIG "【"+HIW+" 少  魔 "+HIG+"】" NOR;
			else if( (int)ob->query("thief") > 10 )
				return HIG"【"+HIW+" 惯  窃 "+HIG+"】"NOR;
			else
                                switch(ob->query("class")) {
                                case "bonze":
                                        if (budd >= 200)
                                                return HIG "【"+HIY+" 大  师 "+HIG+"】" NOR;
                                        else if (budd >= 150)
                                                return HIG "【"+HIY+" 长  老 "+HIG+"】" NOR;
                                        else if (budd >= 120)
                                                return HIG "【"+HIY+" 圣  僧 "+HIG+"】" NOR;
                                        else if (budd >= 90)
                                                return HIG "【"+HIY+" 罗  汉 "+HIG+"】" NOR;
                                        else if (budd >= 60)
                                                return HIG "【"+HIY+" 尊  者 "+HIG+"】" NOR;
                                        else if (budd >= 40)
                                                return HIG "【"+HIY+" 禅  师 "+HIG+"】" NOR;
                                        else if (budd >= 30)
                                                return HIG "【"+HIY+" 比  丘 "+HIG+"】" NOR;
                                        else
                                                return CYN"【"+WHT+" 僧  人 "+CYN+"】"NOR;
                                case "taoist":
                                        if (taoi >= 200)
                                                return HIC "【"+HIG+" 真  人 "+HIC+"】" NOR;
                                        else if (taoi >= 150)
                                                return HIC "【"+HIG+" 天  师 "+HIC+"】" NOR;
                                        else if (taoi >= 100)
                                                return HIC "【"+HIG+" 道  长 "+HIC+"】" NOR;
                                        else if (taoi >= 50)
                                                return HIC "【"+HIG+" 道  人 "+HIC+"】" NOR;
                                        else
                                                return CYN"【"+WHT+" 道  士 "+CYN+"】"NOR;
//					return CYN"【"+WHT+" 道  士 "+CYN+"】"NOR;
                                case "bandit":
                                        return CYN"【"+WHT+" 盗  贼 "+CYN+"】"NOR;
                                case "scholar":
                                        return CYN"【"+WHT+" 书  生 "+CYN+"】"NOR;
                                case "officer":
                                        return CYN"【"+WHT+" 官  差 "+CYN+"】"NOR;
                                case "fighter":
                                        return CYN"【"+WHT+" 武  者 "+CYN+"】"NOR;
                                case "swordsman":
                                        return CYN"【"+WHT+" 剑  士 "+CYN+"】"NOR;
                                case "alchemist":
                                        return CYN"【"+WHT+" 方  士 "+CYN+"】"NOR;
                                case "shaman":
                                        return CYN"【"+WHT+" 巫  医 "+CYN+"】"NOR;
                                case "beggar":
                                        return CYN"【"+WHT+" 叫化子 "+CYN+"】"NOR;
                                default:
                                        return CYN"【"+WHT+" 平  民 "+CYN+"】"NOR;
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
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师太";
                                else return "师太";
                                break;
                        case "taoist":
                                if( age < 18 ) return "小仙姑";
                                else return "仙姑";
                                break;
                        default:
                                if( age < 18 ) return "小姑娘";
                                else if( age < 50 ) return "姑娘";
                                else return "婆婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 18 ) return "小师父";
                                else return "大师";
                                break;
                        case "taoist":
                                if( age < 18 ) return "道兄";
                                else return "道长";
                                break;
                        case "fighter":
                        case "swordsman":
                                if( age < 18 ) return "小老弟";
                                else if( age < 50 ) return "壮士";
                                else return "老前辈";
                                break;
                        default:
                                if( age < 20 ) return "小兄弟";
                                else if( age < 50 ) return "壮士";
                                else return "老爷子";
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
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                return "贼尼";
                                break;
                        case "taoist":
                                return "妖女";
                                break;
                        default:
                                if( age < 30 ) return "小贱人";
                                else return "死老太婆";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "死秃驴";
                                else return "老秃驴";
                                break;
                        case "taoist":
                                return "死牛鼻子";
                                break;
                        default:
                                if( age < 20 ) return "小王八蛋";
                                if( age < 50 ) return "臭贼";
                                else return "老匹夫";
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
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "小女子";
                                else return "妾身";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫僧";
                                else return "老纳";
                                break;
                        case "taoist":
                                return "贫道";
                                break;
                        default:
                                if( age < 50 ) return "在下";
                                else return "老头子";
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
                case "女性":
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "贫尼";
                                else return "老尼";
                                break;
                        default:
                                if( age < 30 ) return "本姑娘";
                                else return "老娘";
                                break;
                        }
                case "男性":
                default:
                        switch(ob->query("class")) {
                        case "bonze":
                                if( age < 50 ) return "大和尚我";
                                else return "老和尚我";
                                break;
                        case "taoist":
                                return "本山人";
                                break;
                        default:
                                if( age < 50 ) return "大爷我";
                                else return "老子";
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
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
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
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
        }
        return "错误：rankd.c -> query_self_close()\n";
}
//=========================以下为了完成imud的emote功能而补充====================
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
        case "女性" :
                if (a1 >= a2)
                        return "姐姐我";
                else
                        return "小妹我";
                break;
        default :
                if (a1 >= a2)
                        return "愚兄我";
                else
                        return "小弟我";
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
        case "女性" :
                if (a1 >= a2)
                        return "妹妹";
                else
                        return "姐姐";
                break;
        default :
                if (a1 >= a2)
                        return "弟弟";
                else
                        return "哥哥";
        }
}
