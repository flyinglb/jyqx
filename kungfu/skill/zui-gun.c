// zui-gun.c -ÉÙÁÖ×í¹÷
inherit SKILL;
mapping *action = ({
([  "action":"¡¸"+MAG+"À¶²ÉºÍ"+CYN+"£¬ÌáÀºÈ°¾Æ×íëüëÊ"+NOR+"¡¹£¬$NÊÖÖÐ$w°ëÌá£¬»º»º»®Ïò$nµÄ$l",
    "force" : 180,
    "lvl" : 0,
    "skill_name" : MAG " À¶²ÉºÍ£¬ÌáÀºÈ°¾Æ×íëüëÊ" NOR,
    "damage_type":"ÓÙÉË"
]),
([  "action":"¡¸"+HIC+"ºÎÏÉ¹Ã£¬À¹Ñü¾´¾Æ×íÏÉ²½"+NOR+"¡¹£¬$N×óÕÆ»¤ÐØ£¬ÓÒ±ÛÐ®¹÷ÃÍµØÉ¨Ïò$nµÄÑü¼ä",
    "force" : 200,
    "lvl" : 20,
    "skill_name" : HIC "ºÎÏÉ¹Ã£¬À¹Ñü¾´¾Æ×íÏÉ²½" NOR ,
    "damage_type":"ÓÙÉË"
]),
([  "action":"¡¸"+WHT+" ²Ü¹ú¾Ë£¬Ç§±­²»×íµ¹½ðÖÑ"+NOR+" ¡¹£¬$Nµ¹Êú$w£¬Ö¸Ìì´òµØ£¬Ïò$nµÄ$lÅüÈ¥",
    "force" : 230,
    "lvl" : 30,
    "skill_name" : WHT "²Ü¹ú¾Ë£¬Ç§±­²»×íµ¹½ðÖÑ" NOR,
    "damage_type":"ÄÚÉË"
]),
([  "action":"¡¸"+RED+"º«Ïæ×Ó£¬Ìú¹÷ÌáÐØ×í°ÎÏô"+NOR+"¡¹£¬$NºáÌá$w£¬¹÷¶Ë»®ÁË¸ö°ëÈ¦£¬»÷Ïò$nµÄ$l",
    "force" : 270,
    "lvl" : 40,
    "skill_name" : RED "º«Ïæ×Ó£¬Ìú¹÷ÌáÐØ×í°ÎÏô" NOR,
    "damage_type":"´ÌÉË"
]),
([  "action":" ¡¸"+YEL+"ººÖÓÀë£¬µø²½·­Éí×íÅÌÁú"+NOR+"¡¹£¬$NÊÖÖÐ¹÷»¨ÍÅÍÅ£¬¼²·ç°ãÏò¾íÏò$n",
    "force" : 320,
    "lvl" : 50,
    "skill_name" : YEL "ººÖÓÀë£¬µø²½·­Éí×íÅÌÁú" NOR,
    "damage_type":"ÓÙÉË"
]),
([  "action":"¡¸"+HIW+"Ìú¹ÕÀî£¬Ìßµ¹½ðÉ½×íÓñ³Ø"+NOR+"¡¹£¬$Nµ¥ÍÈÖ§µØ£¬Ò»ÍÈÒ»¹÷ÆëÆë»÷Ïò$nµÄ$l",
    "force" : 380,
    "lvl" : 55,
    "skill_name" : HIW "Ìú¹ÕÀî£¬Ìßµ¹½ðÉ½×íÓñ³Ø" NOR,
    "damage_type":"ÓÙÉË"
]),
([  "action":"¡¸"+HIR+"ÕÅ¹ûÀÏ£¬×í¾ÆÅ×±­µ¹ÆïÂ¿"+NOR+"¡¹£¬$NÅ¤Éí·´±³£¬$w´Ó¿èµ××ê³ö£¬´ÁÏò$nµÄÐØ¿Ú",
    "force" : 450,
    "lvl" : 60,
    "skill_name" : HIR "ÕÅ¹ûÀÏ£¬×í¾ÆÅ×±­µ¹ÆïÂ¿" NOR,
    "damage_type":"´ìÉË"
]),
([  "action":"¡¸"+BLU+"ÂÀ¶´±ö£¬¾Æ×íÌáºøÁ¦Ç§¾û"+NOR+"¡¹£¬$NÌÚ¿Õ¶øÆð£¬ÈçÉ½¹÷Ó°£¬¼²¼²Ñ¹Ïò$n",
    "force" : 530,
    "lvl" : 64,
    "skill_name" : BLU "ÂÀ¶´±ö£¬¾Æ×íÌáºøÁ¦Ç§¾û" NOR,
    "damage_type":"´ìÉË"
]),
});
int valid_enable(string usage) { return (usage == "club") || (usage == "parry"); }
int practice_level(){   return 64;  }
int valid_learn(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
    if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
        return notify_fail("ÄãµÄ»ìÔªÒ»Æø¹¦»ðºòÌ«Ç³¡£\n");
    if (me->query_skill("club", 1) <=me->query_skill("zui-gun", 1))
        return notify_fail("ÄãµÄ»ù´¡²»¹»£¬ÎÞ·¨Áì»á¸ü¸ßÉîµÄ¼¼ÇÉ¡£\n");
    return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("zui-gun",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "club")
        return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
    if ((int)me->query("qi") < 50)
        return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·ÉÙÁÖ×í¹÷¡£\n");
    me->receive_damage("qi", 25);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"zui-gun/" + action;
}

