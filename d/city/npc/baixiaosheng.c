// baixiaosheng.c
inherit NPC;
#include <ansi.h>;
int time_period(int timep,object me);
void create()
{
	set_name(HIW"百晓生"NOR, ({ "bai xiaosheng", "bai", "xiaosheng" }));
	set("title", HIR"什么都不知道"NOR);
	set("gender", "男性");
	set("age", 50);
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("per", 30);
	set("long","这就是江湖中人称“无所不知”的百晓生，看起来只有二十多岁，其实他已经五十多岁了。”\n");
	set("combat_exp", 800000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("max_qi", 2500);
	set("max_jing", 1000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 50);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("hand", 200);
	set_skill("dodge", 200);
	set_skill("shenxing-baibian", 200);
	set_skill("yunlong-shengong", 200);
	set_skill("qianye-shou", 200);
	map_skill("force", "yunlong-shengong");
	map_skill("parry", "qianye-shou");
	map_skill("dodge", "shenxing-baibian");
	map_skill("hand", "qianye-shou");
	prepare_skill("hand", "qianye-shou");

	set("inquiry", ([
		"杀情"    : "你说他啊，这孩子MUD玩的不怎么样，喜欢学习接受新事物，是个又傻又痴情的孩子。\n",
		"小小鱼"  : "小小鱼？那不是天上嫦娥养的鱼吗？怎么下凡来了？\n",
                "靓宝宝"  : "此姝原应天上有，不合生长在人间，不就指她吗！\n",
                "绝影寒笙"  : "他原本是邪派中的高手，后经高人指点，终于弃恶从善，成为一代宗师。\n",
		"水柔晶"  : "她是这里最美丽温柔的女孩了，谁娶了她不知道有多幸福，不过她不喜欢打打杀杀！\n",
		"龙之麟"  : "龙之麟，24，已婚。\n",
		"韩柏"    : "韩柏？就是说的那个行侠仗义，最喜欢帮助新手的COC了吧？他只有一句话来形容，简直是太酷了！\n",
		"百晓生"  : "别问我，我什么都不知道。\n",
		"小小强"  : "小小强，武功差，经验也不多，没什么好的，别pk他啊。\n",
		"寒林"    : "只要堕落...只爱堕落.....因为我老婆是堕落天使啊...哈哈'.'。\n",
		])
	);
	setup();
	carry_object("/clone/cloth/male2-cloth")->wear();
}
