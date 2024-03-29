//anranxiaohun-zhang.c 黯然消魂掌
// By Kayin @ CuteRabbit Studio 99-4-16 16:22 new

inherit SKILL;
#include <ansi.h>
mapping *action = ({
([	"action" : "$N一招"HIW"杞人忧天"NOR"抬头向天，浑若不见，呼的一掌向自己头顶空空拍出，手掌斜下，掌力化成弧形，四散落下拍向$n的$l。",
	"force" : 250,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"damage" : (int)this_player()->query("age")*2,
	"lvl" : 0,
	"skill_name" : "杞人忧天",
	"damage_type" : "内伤"
]),
([	"action" : "$N一招"HIG"无中生有"NOR"手臂下垂，绝无半点防御姿式，突然间手足齐动，左掌右袖、双足头锤、连得胸背腰腹尽皆有招式发出撞向$n.",
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"force" : 250,
	"damage" : (int)this_player()->query("age")*3,
	"lvl" : 10,
	"skill_name" : "无中生有",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIB"拖泥带水"NOR"右手云袖飘动，宛若流水，左掌却重滞之极，便似带着几千斤泥沙一般，左右齐攻$n。",
	"force" : 250,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*4,
	"lvl" : 20,
	"skill_name" : "拖泥带水",
	"damage_type" : "内伤"
]),

([	"action" : "$N一招"HIY"力不从心"NOR"含胸收腹，头缓缓低下，脚步沉重的迈向$n,右掌软绵绵的拍向$n的$l。",
	"force" : 300,
	"damage" : (int)this_player()->query("age")*5,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"lvl" : 30,
	"skill_name" : "力不从心",
    "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIR"行尸走肉"NOR"踢出一脚。这一脚发出时恍恍惚惚，隐隐约约，若有若无的踢向$n",
	"force" : 250,
	"damage" : (int)this_player()->query("age")*6,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"lvl" : 40,
	"skill_name" : "行尸走肉",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N双掌平托，一招"HIM"庸人自扰"NOR"没精打采的拍向$n的$l.",
	"force" : 250,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*7,
	"lvl" : 50,
	"skill_name" : "庸人自扰",
            "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"RED"倒行逆施"NOR"突然纵起丈余，头下脚上，倒过身子，一掌拍向$n的$l",
	"force" : 250,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"damage" : (int)this_player()->query("age")*8,
	"lvl" : 60,
	"skill_name" : "倒行逆施",
	"damage_type" : "瘀伤"
]),
([	"action" : "$N一招"YEL"心惊肉跳"NOR"凝目远眺，脚下虚浮，胸前门户洞开，全身姿式与武学中各项大忌无不吻合。",
	"force" : 300,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"damage" : (int)this_player()->query("age")*9,
	"lvl" : 70,
	"skill_name" : "心惊肉跳",
           "damage_type" : "内伤"
]),
([	"action" : "$N一招"BLU"废寝忘食"NOR"脚下虚浮，有如几天不吃不睡后的脚步朗舱的袭到$n的身旁，左掌右拳攻向$n的$l。",
	"force" : 300,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*10,
	"lvl" : 80,
	"skill_name" : "废寝忘食",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIC"徘徊空谷"NOR"左攻右打，虚虚实实的攻向$n的$l。",
	"force" : 300,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*11,
	"lvl" : 90,
	"skill_name" : "徘徊空谷",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"CYN"饮恨吞声"NOR"左手做饮酒状，右掌斜斜劈向$n的$l。",
	"force" : 350,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*12,
	"lvl" : 100,
	"skill_name" : "饮恨吞声",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"MAG"六神不安"NOR"身如陀螺急转，展开轻功围着$n快速游走，忽然飞身而起，拍向$n的$l。",
	"force" : 400,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*13,
	"lvl" : 110,
	"skill_name" : "六神不安",
           "damage_type" : "内伤"
]),
([	"action" : "$N一招"WHT"穷途末路"NOR"闪身到$n身旁，左掌举到胸前平推而出，接着右掌斜斜劈向$n的$l。",
	"force" : 450,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*14,
	"lvl" : 120,
	"skill_name" : "穷途末路",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIY"呆若木鸡"NOR"双目直直的盯着$n，身体动也不动一下的飞向$n",
	"force" : 500,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*15,
	"lvl" : 130,
	"skill_name" : "呆若木鸡",
           "damage_type" : "内伤"
]),
([	"action" : "$N低头冥想，一招"HIB"若有所失"NOR"右掌向外平平推向$n的$l。",
	"force" : 550,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*16,
	"lvl" : 140,
	"skill_name" : "若有所失",
           "damage_type" : "瘀伤"
]),
([	"action" : "$N一招"HIB"四通八达"NOR"双掌晃出千万掌影将$n笼罩在掌力之下。",
	"force" : 600,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*17,
	"lvl" : 150,
	"skill_name" : "四通八达",
           "damage_type" : "内伤"
]),
([	"action" : "$N错步上前，一招"HIB"鹿死谁手"NOR"招招抢先，以快打慢，一个转身已经转到了$n的身后，运指如风点向$n的大椎穴。",
	"force" : 800,
	"dodge" : (int)this_player()->query_skill("dodge")/2,
	"attack":this_player()->query_skill("anranxiaohun-zhang",1),
	"damage" : (int)this_player()->query("age")*18,
	"lvl" : 160,
	"skill_name" : "鹿死谁手",
           "damage_type" : "点穴"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }

int valid_combine(string combo) { return combo=="anranxiaohun-zhang"; }

int valid_learn(object me)
{
	if(!me->query("couple/have_couple")) 
		return notify_fail("你还没有所爱的人，不能领会其中的精要！\n");
	if (me->query("gender") != "男性") 
                return notify_fail("你体会不到男人思念一个人的心情。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练黯然消魂掌必须空手。\n");
        if( (int)me->query_skill("yunv-xinfa",1)<100)
                return notify_fail("你的玉女心法等级不够。\n");
	if ((int)me->query("max_neili") < 2000)
		return notify_fail("你的内力太弱，无法练黯然消魂掌。\n");
	if ((int)me->query_str()< 40)
		return notify_fail("你的臂力太弱，无法练黯然消魂掌。\n");	
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("anranxiaohun-zhang",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 50, level)];
}

int practice_skill(object me)
{
        if (me->query_skill("anranxiaohun-zhang",1) < 101)
                return notify_fail("你目前只能来学黯然消魂掌。\n");    
	if ((int)me->query("qi") < 60)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练黯然消魂掌。\n");
	me->receive_damage("qi", 60);
	me->add("neili", -50);
	return 1;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( damage_bonus/2 > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
		return HIR "只听到“哇”的一声，"+ victim->name()+"喷出了一大口鲜血！\n" NOR;
	}
}
string perform_action_file(string action)
{
	return __DIR__"anranxiaohun-zhang/" + action;
}

