// lu.c
#include <command.h>
#include <ansi.h>
inherit NPC;                                                                    
inherit F_MASTER;                                                               
void create()
{
        set_name( "陆乘风" ,({ "lu chengfeng", "lu" }));
        set("gender", "男性");
        set("age", 52);
        set("long",
            "陆乘风是黄药师的第四个徒弟。\n"
            "他的鬓角已微见白发，但身材魁梧，双眼有神。\n");
        set("attitude", "friendly");
        set("class", "scholar");
        set("str", 30);
        set("int", 28);
        set("con", 30);
        set("dex", 30);
        set("chat_chance", 1);
        set("max_qi",1500);
        set("max_jing",500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        set("shen_type",1);

        set("combat_exp", 300000);
        set_skill("force", 90);             // 基本内功
        set_skill("bibo-shengong", 80);     // 碧波神功
        set_skill("unarmed", 90);           // 基本拳脚
        set_skill("xuanfeng-leg", 90);      // 旋风扫叶腿
        set_skill("strike", 90);            // 基本掌法
        set_skill("luoying-zhang", 90);     // 落英神剑掌
        set_skill("dodge", 70);             // 基本躲闪
        set_skill("anying-fuxiang", 70);    // 暗影浮香
        set_skill("parry", 90);             // 基本招架
        set_skill("sword", 90);             // 基本剑法
        set_skill("luoying-shenjian", 90);  // 落英神剑
        set_skill("literate",90);           // 读书识字

        map_skill("force"  , "bibo-shengong");
        map_skill("unarmed", "xuanfeng-leg");
        map_skill("strike" , "luoying-zhang");
        map_skill("dodge"  , "anying-fuxiang");
        map_skill("parry"  , "luoying-shenjian");
        map_skill("sword"  , "luoying-shenjian");

        set("jinbing", 10);
        create_family("桃花岛", 2, "弟子 归云庄主");

        set("inquiry", ([
           "桃花岛":   "这儿就是桃花岛，你若不是本派弟子，要过桃花阵。",
           "桃花阵":   "往南就是了。",
           "东邪":     "家师人称东邪！呵呵。",
           "西毒":     "欧阳锋是与家师并世齐名的高手，人称老毒物。",
           "南帝":     "听家师说段王爷现在出家当了和尚，法名一灯。",
           "北丐":     "北丐洪七公是丐帮帮主，现在扬州城外。",
           "黄蓉":     "她是师父的爱女。",
           "黄药师":   "你要拜访家师？"
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian");
}

void attempt_apprentice(object ob)
{
        if (ob->query_dex() < 20)
        {
           command("say 我派武功讲究轻灵巧捷。");
           command("say 这位"+RANK_D->query_respect(ob)+"可能是白来归云庄一趟了。");
           return;
        }
        if ((int)ob->query("shen") < 0)
        {
           command("say 我派在江湖中立身尚正，"+ RANK_D->query_respect(ob)+"请回吧。");
           return;
        }
        if (ob->query("gender") == "无性")
        {
           command("say 师父最讨厌不男不女的东西了，这位"+RANK_D->query_respect(ob)+"赶快请吧。");
           return;
        }
        if (ob->query("class") == "bonze")
        {
           command("say 师父最爱非僧抑道了，这位"+RANK_D->query_respect(ob)+"还是请回吧。");
           return;
        }
        if (ob->query_skill("literate",1) <= 10)
        {
           command("say 桃花岛只收读书人作弟子，这位"+RANK_D->query_respect(ob)+"是否去读点书再来。");
           return;
        }
        command("smile");
        command("say " + RANK_D->query_respect(ob) + "入我门下，需努力不堕。");
        command("recruit " + ob->query("id"));
}
int accept_fight(object ob)
{
        command("wield jian");
}
int accept_object(object who, object ob)
{
	int exp;
	if (query("jinbing") < 0)
	{
                command("say " + RANK_D->query_respect(who) + "我很累，你回头再来领赏吧。");
		return 0;
	}
	if (strsrch(ob->query("name"), "完颜康的头颅") < 0 &&
	    strsrch(ob->query("name"), "完颜洪烈的头颅") < 0 &&
	    strsrch(ob->query("name"), "欧阳锋的头颅") < 0 &&
	    strsrch(ob->query("name"), "欧阳克的头颅") < 0 &&
	    strsrch(ob->query("name"), "彭连虎的头颅") < 0 &&
	    strsrch(ob->query("name"), "梁子翁的头颅") < 0 &&
	    strsrch(ob->query("name"), "灵智上人的头颅") < 0 &&
	    strsrch(ob->query("name"), "沙通天的头颅") < 0 &&
	    strsrch(ob->query("name"), "侯通海的头颅") < 0 &&
	    strsrch(ob->query("name"), "沈青刚的头颅") < 0 &&
	    strsrch(ob->query("name"), "吴青烈的头颅") < 0 &&
	    strsrch(ob->query("name"), "马青雄的头颅") < 0 &&
	    strsrch(ob->query("name"), "钱青健的头颅") < 0 &&
	    strsrch(ob->query("name"), "大金兵的头颅") < 0 &&
	    strsrch(ob->query("name"), "段天德的头颅") < 0) 
	{
                command("say 给我这些东西有什么用？\n");
		return 0;
	}
	else
	{
                command("say 不错不错，我一直想杀这些金狗，谢你代劳了。");
	}
	exp = 20+random(30);
	add("jinbing", -1);
	tell_object(who,HIW"陆乘风奖励了你\n"+chinese_number(exp)+"点实战经验\n"NOR);
	return 1;
}
