// taixuan-gong.c 侠客岛太玄功
// Jay 4/5/96
// modified by wind
inherit FORCE;

string *dodge_msg = ({
    "$n左手拍出，劲风到处，把$N震到一边。\n",
    "$n手臂回转，抓住$N手肘一推，将$N远远掷开。\n",
    "$n两腿轻蹬，激跃而出，竟已落在十数丈外。\n",
    "$N只觉眼前一花，只见到$n身形一幌，自己的招数居然莫名其妙就落空了。\n",
});

mapping *action = ({
([  "action":"$N双手一举，一股劲气澎湃汹涌而来，逼得$n踉踉后退",
    "force" : 200,
    "dodge" : 20,
    "damage": 240,
    "damage_type":  "瘀伤"
]),
([  "action":"$N右手伸出，在$n臂膀上迅速无比的一按，$n一跤跌了出去",    
    "force" : 220,
    "dodge" : 20,
    "damage": 250,
    "damage_type":  "瘀伤"
]),
([  "action":"$N大喝一声，张口一股内气向$n脸上喷去",
    "force" : 400,
    "dodge" : 30,
    "damage": 250,
    "damage_type":  "瘀伤"
]),
([  "action":"$N猱身而上，双掌猛地拍向$n",
    "force" : 225,
    "dodge" : 30,
    "damage": 270,
    "damage_type":  "瘀伤"
]),
([  "action":"$N身体微侧，突然飞起一脚，踢向$n下三路。脚到中途，猛地一抬，踢向$n面门",
    "force" : 230,
    "dodge" : 40,
    "damage": 300,
    "damage_type":  "瘀伤"
]),
([  "action":"$N突然间左手一捺，封住$n退路，右手掌力汹涌而出",
    "force" : 230,
    "dodge" : 40,
    "damage": 300,
    "damage_type":  "瘀伤"
]),

});

int valid_enable(string usage)
{
    return usage == "unarmed" || usage == "dodge" || usage == "parry" || usage == "force";
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("taixuan-gong",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
       return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
    if (random(this_player()->query("kar")) > 25)
        return 1;
    return notify_fail("你对着石壁冥思苦想了一会，对满目蝌蚪文一点不懂。\n");
}

string exert_function_file(string func)
{
    return __DIR__"taixuan-gong-e/" + func;
}

string perform_action_file(string action)
{
    return __DIR__"taixuan-gong-p/" + action;
}
