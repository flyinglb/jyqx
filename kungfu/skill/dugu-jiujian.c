// dugu-jiujian.c 独孤九剑
inherit SKILL;
string *parry_msg = ({
        "$n以攻为守，以进为退，凝神运气向$P猛攻快打地挥出方位大异的泰山「"+MAG+"快活三"+NOR+"」三剑。\n",
        "$n剑法突变，剑势伸缩不定，奔腾矫夭，逆使嵩山剑法的「"+YEL+"天外玉龙"+NOR+"」企图迫使$P变招。\n",
        "$n突然使出青城派松风剑法的「"+RED+"鸿飞冥冥"+NOR+"」，可是方位却有所偏差，长剑对着$P一绞，企\n图突破$P的攻势！\n",
        "只见$n不退反进，身如飘风，诡异地一式「"+HIW+"天柱云气"+NOR+"」，动向无定不可捉摸地挡住了$P的\n进攻。\n",
        "$n不退反进，使出恒山剑招「"+HIR+"绵里藏针"+NOR+"」，森森剑气充溢四周！架开了$P的这招\n",
});
string *parry_msg2 = ({
        "$n不闪不避，举剑闪电般使出「"+BLU+"叠翠浮青"+NOR+"」反削$P的$l。\n",
        "却见$n踏前一步，剑式斜指$N的右臂，想要使$N闪身而退。\n",
        "$n突然一剑点向$P的$l，虽一剑却暗藏无数后着，$P手足无措，慌忙撤手回防！\n",
        "$n挺剑一招象是「"+HIW+"白云出岫"+NOR+"」回刺$P的$l，企图将$P的攻势化解。\n",
});

mapping *action = ({
([  "action" : "但见$N挺身而上，$w一旋，一招仿佛泰山剑法的「"+HIC+"来鹤清泉"+NOR+"」直刺$n的$l！",
    "force" : 10,
    "dodge" : -5,
    "damage": 30,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([  "action" : "$N奇诡地向$n挥出「"+RED+"泉鸣芙蓉"+NOR+"」、「"+YEL+"鹤翔紫盖"+NOR+"」、「"+BLU+"石廪书声"+NOR+"」、「"+MAG+"天柱云气"+NOR+"」\n及「"+YEL+"雁回祝融"+NOR+"」衡山五神剑！",
    "force" : 10,
    "dodge" : -10,
    "damage": 30,
    "lvl" : 7,
    "damage_type" : "刺伤"
]),
([
    "action" : "$N剑随身转，续而刺出十九剑，竟然是华山「"+MAG+"玉女十九剑"+NOR+"」，但奇的是这十九\n剑便如一招，手法之快，直是匪夷所思！",
    "force" : 10,
    "dodge" : -5,
    "damage": 40,
    "lvl" : 14,
    "damage_type" : "刺伤"
]),
([  "action" : "$N剑势忽缓而不疏，剑意有余而不尽，化恒山剑法为一剑，向$n慢慢推去！",
    "force" : 20,
    "dodge" : -15,
    "damage": 40,
    "lvl" : 21,
    "damage_type" : "刺伤"
]),
([  "action" : "$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，尽括嵩山\n剑势击向$n的$l！",
    "force" : 20,
    "dodge" : -20,
    "damage": 50,
    "lvl" : 28,
    "damage_type" : "刺伤"
]),
([  "action" : "却见$N身随剑走，左边一拐，右边一弯，剑招也是越转越加狠辣，竟化「"+HIG+"泰山十八盘"+NOR+"」\n为一剑攻向$n！",
    "force" : 30,
    "dodge" : -25,
    "damage": 55,
    "lvl" : 35,
    "damage_type" : "刺伤"
]),
([  "action" : "$N剑招突变，使出衡山的「"+HIC+"一剑落九雁"+NOR+"」，削向$n的$l，怎知剑到中途，突然转\n向，大出$n意料之外！",
    "force" : 40,
    "dodge" : -35,
    "damage": 60,
    "lvl" : 42,
    "damage_type" : "刺伤"
]),
([  "action" : "$N吐气开声，一招似是「"+WHT+"独劈华山"+NOR+"」，手中$w向下斩落，直劈向$n的$l！",
    "force" : 50,
    "dodge" : -40,
    "damage": 80,
    "lvl" : 49,
    "damage_type" : "刺伤"
]),
([  "action" : "$N手中$w越转越快，使的居然是衡山的「"+MAG+"百变千幻云雾十三式"+NOR+"」，剑式有如云\n卷雾涌，旁观者不由得目为之眩！",
    "force" : 60,
    "dodge" : -45,
    "damage": 70,
    "lvl" : 56,
    "damage_type" : "刺伤"
]),
([  "action" : "$N含笑抱剑，气势庄严，$w轻挥，尽融「达摩剑」为一式，闲舒地刺向$n！",
    "force" : 70,
    "dodge" : -50,
    "damage": 90,
    "lvl" : 63,
    "damage_type" : "刺伤"
]),
([  "action" : "$N举起$w运使「太极剑」剑意，划出大大小小无数个圆圈，无穷无尽源源不绝地\n缠向$n！",
    "force" : 80,
    "dodge" : -60,
    "damage": 80,
    "lvl" : 70,
    "damage_type" : "刺伤"
]),
([  "action" : "$N神声凝重，$w上劈下切左右横扫，挟雷霆万钧之势逼往$n，「伏摩剑」的剑意\n表露无遗！",
    "force" : 90,
    "dodge" : -65,
    "damage": 90,
    "lvl" : 77,
    "damage_type" : "刺伤"
]),
([  "action" : "却见$N突然虚步提腰，使出酷似武当「"+BLU+"蜻蜓点水"+NOR+"」的一招！",
    "force" : 100,
    "dodge" : -70,
    "damage": 60,
    "lvl" : 84,
    "damage_type" : "刺伤"
]),
([  "action" : "$N运剑如风，剑光霍霍中反攻$n的$l，尝试逼$n自守，剑招似是伏魔剑\n的「"+RED+"龙吞式"+NOR+"」。",
    "force" : 120,
    "dodge" : -75,
    "damage": 95,
    "lvl" : 91,
    "damage_type" : "刺伤"
]),
([  "action" : "$N突然运剑如狂，一手关外的「"+YEL+"乱披风剑法"+NOR+"」，猛然向$n周身乱刺乱削！",
    "force" : 140,
    "dodge" : -80,
    "damage": 120,
    "lvl" : 98,
    "damage_type" : "刺伤"
]),
([  "action" : "$N满场游走，东刺一剑，西刺一剑，令$n莫明其妙，分不出$N剑法的虚实！",
    "force" : 160,
    "dodge" : -90,
    "damage": 50,
    "lvl" : 105,
    "damage_type" : "刺伤"
]),
([  "action" : "$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法！",
    "force" : 180,
    "dodge" : -95,
    "damage": 80,
    "lvl" : 112,
    "damage_type" : "刺伤"
]),
([  "action" : "$N突然一剑点向$n的$l，虽一剑却暗藏无数后着，$n手足无措，不知如何是好！",
    "force" : 200,
    "dodge" : -100,
    "damage": 85,
    "lvl" : 119,
    "damage_type" : "刺伤"
]),
([  "action" : "$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫得$n不得不守！",
    "force" : 220,
    "dodge" : -110,
    "damage": 100,
    "lvl" : 126,
    "damage_type" : "刺伤"
]),
([  "action" : "$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n难以看清\n剑招来势！",
    "force" : 240,
    "dodge" : -115,
    "damage": 120,
    "lvl" : 133,
    "damage_type" : "刺伤"
]),
([  "action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招式。",
    "force" : 260,
    "dodge" : -120,
    "damage": 100,
    "lvl" : 140,
    "damage_type" : "刺伤"
]),
([  "action" : "$N随手一剑指向$n，落点正是$n的破绽所在，端的是神妙无伦，不可思议！",
    "force" : 280,
    "dodge" : -130,
    "damage": 60,
    "lvl" : 147,
    "damage_type" : "刺伤"
]),
([  "action" : "$N脸上突现笑容，似乎已看破$n的武功招式，胸有成竹地一剑刺向$n的$l！",
    "force" : 300,
    "dodge" : -150,
    "damage": 120,
    "lvl" : 154,
    "damage_type" : "刺伤"
]),
([
    "action" : "$N将$w随手一摆，但见$n自己向$w撞将上来，神剑之威，实人所难测！",
    "force" : 400,
    "dodge" : -160,
    "damage": 165,
    "lvl" : 180,
    "damage_type" : "刺伤"
])
});

int valid_enable(string usage)
{
    return (usage == "sword") || (usage == "parry");
}
string query_parry_msg(object me,object weapon)
{
    object my_weapon;

    if (!(my_weapon=me->query_temp("weapon"))){
    	if (!(my_weapon=me->query_temp("secondary_weapon")))
		  return "";
     }else{
	    if (!valid_enable(my_weapon->query("skill_type"))){
    		if (!(my_weapon=me->query_temp("secondary_weapon")))
				  return "";
			else			
			    if (!valid_enable(my_weapon->query("skill_type")))
				  return "";
	    }
	}
    if (weapon)
    	return parry_msg[random(sizeof(parry_msg))];
	else
	    return parry_msg2[random(sizeof(parry_msg2))];
}

int valid_learn(object me)
{
	if (me->query("family/master_id")!="feng qingyang")
        return notify_fail("独孤九剑是风清扬所创，其他师傅参悟还来不及，怎能教你？\n");
    if ((int)me->query("max_neili") < 2000)
        return notify_fail("你的内力不够。\n");
    if (me->query_skill("sword", 1) <=me->query_skill("dugu-jiujian", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
    if ((int)me->query_skill("dugu-jiujian",1) > 60)
        return notify_fail("这套剑法我就教到这儿，以后就要靠你自己练了。\n");
    return 1;
}
mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
int practice_skill(object me)
{
    return notify_fail("独孤九剑只能通过「"+RED+"总诀式"+NOR+"」来演练。\n");
}
string perform_action_file(string action)
{
    return __DIR__"dugu-jiujian/" + action;
}
