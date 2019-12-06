// mantian-xing.c ÂúÌìĞÇ
// modified by Venus Oct.1997
#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
    "$n×óÒ»µãÓÒÒ»»Î£¬Ëæ¼´»Øµ½Ô­µØ£¬ÇáÇÉµØ¶ã¹ıÁË$NÕâÒ»ÕĞ¡£\n",
    "$nÌÚÉíÔ¾ÆğÒ»¸ö¿Õ·­£¬²¢Ë³ÊÆÉÁµ½Ò»±ß¡£\n",
    "$nÇáÇáÍùÅÔ±ßÒ»×İ£¬¾ÍÒÑÀë$NÓĞÁËÏàµ±µÄ¾àÀë£¬$NÕâÒ»ÕĞ×ÔÈ»Ê§Ğ§¡£\n",
    "$nÈàÉí¶øÉÏ£¬ÇáÁéµØÔ¾¹ı$N£¬ÉÁµ½ÁË$NµÄ±³ºó¡£\n",
    "$nÉíĞÎ¼±ÉÁ£¬Ğ±ÏòÇ°Ò»²½£¬¾¹È»ÒÑ¾­¶ã¿ªÁË$NµÄÕâÒ»ÕĞ¡£\n",
    "$NÑÛÇ°Ò»»¨£¬È´¼û$n¾¹È»ÒÑÀë×Ô¼ºÓĞÊıÕÉÖ®Ô¶£¬È´Ã»¼û$nÈçºÎ¶ã¹ı×Ô¼ºµÄ¹¥»÷µÄ¡
£\n",
    "$NÒ»¸ö²»ÁôÉñ£¬$nÒÑÃ»ÁË×ÙÓ°¡£$N¼±×ªÉí£¬È´¼û$nÔÚÄÇ¶ùÏò×Ô¼ºÕĞÊÖ¡£\n",
    "$NÒ»ÕĞ¹¥³ö£¬$nÒÑÈ»²»¼û£¬$NÃ£È»ËÄ¹Ë£¬È´²»¼û$nµÄÓ°×Ó£¡\n",
});

mapping *action = ({
([      "action" : "$NÇáÉí¶øÍË£¬Ò»ÕĞ¡º³õÂ¶ĞÇÃ¢¡»£¬ÊÖÖĞ$w»¯×÷Ò»µãº®Ã¢ÉäÏò$n",    
    "damage": 30,
    "dodge" : 40,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 0,
    "skill_name" : "³õÂ¶ĞÇÃ¢"
]),
([      "action" : "$NÓÒÊÖÎ¢ÏòÇ°Ò»Éì£¬Ê¹³ö¡ºÕ§¼ûĞÇ³½¡»£¬ÊÖÀï$w¾¶Ö±ÉäÏò$nµÄË«ÑÛ",
    "damage": 40,
    "dodge" : 45,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 9,
    "skill_name" : "Õ§¼ûĞÇ³½"
]),
([      "action" : "$NÒ»ÉùÇáĞ¥£¬Ê©Õ¹³ö¡ºº®Ò¹¹ÂĞÇ¡»£¬ÉíĞÎÎ¢¶¯£¬ÊÖÖĞ$w¾¹È»ÏòÉÏ·É  
ÆğÈÆÁË¸öÈ¦£¬Ëæ¶øÑ¸ËÙÏ®Ïò$nµÄÑü¼ä",
    "damage": 50,
    "dodge" : 50,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 18,
    "skill_name" : "º®Ò¹¹ÂĞÇ"
]),
([      "action" : "$NÊ¹Ò»ÕĞ¡ºĞÇ¹âÉÁË¸¡»£¬Í»È»×İÉíÏòºóÒ»¸ö·­¹ö£¬¾ÍÔÚ¿ìÂäµØµÄÒ»Ë²
¼ä£¬$n¶¸È»·¢ÏÖ¼¸µãº®¹âÉÁË¸²»¶¨µØÏ®Ïò×Ô¼º",
    "damage": 55,
    "dodge" : 55,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "ÔúÉË",
    "lvl" : 27,
    "skill_name" : "ĞÇ¹âÉÁË¸"
]),
([      "action" : "$NÓÒÊÖÒ»»Ó£¬Ò»ÕĞ¡ºĞÇÃ¢²»¶¨¡»£¬$nÃ÷Ã÷¿´¼û$NÊÖÀïµÄ$wÒÑÉäÏò×Ô¼º
µÄĞØÇ°´óÑ¨£¬µ½ÁË½ü´¦È´Í»È»×ª¹¥Ïò×Ô¼ºµÄºóĞÄ",
    "damage": 60,
    "dodge" : 60,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 36,
    "skill_name" : "ĞÇÃ¢²»¶¨"
]),
([      "action" : "$N²»¼±²»»ºµØÒ»°«Éí£¬Ê¹³ö¡º×¹ÂäÖ®ĞÇ¡»£¬ÊÖÖĞ$wÆ½Ö±µØÉäÏò$nµÄÑÊ
ºí£¬È´ÓÖ¼ÓÉÏ°µ¾¢Ê¹Ö®ÖĞÍ¾¸ÄÏò£¬ÉäÏò$nµÄÏÂÅÌ",
    "damage": 70,
    "dodge" : 70,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 45,
    "skill_name" : "×¹ÂäÖ®ĞÇ"
]),
([      "action" : "$NÌÚÉíÒ»Ô¾¶øÆğ£¬Ê©Õ¹³ö¡ºÀèÃ÷Ö®ĞÇ¡»£¬ÊÖÀïµÄ$w´ÓÉÏÍùÏÂ±ÊÖ±µØÉä
Ïò$nµÄÍ·²¿",
    "damage": 85,
    "dodge" : 80,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 54,
    "skill_name" : "ÀèÃ÷Ö®ĞÇ"
]),
([      "action" : "$NÔ­µØÒ»¸ö¼±×ªÉí£¬Ëæ¼´Ë«ÊÖÒ»·÷£¬$w¾ÍÆ®Æ®ºöºöµØ·ÉÏò$n£¬Ô­À´Õâ
ÕĞÊÇ¡ºĞÇ³½ÓÎÀë¡»",
    "damage": 110,
    "dodge" : 85,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 63,
    "skill_name" : "ĞÇ³½ÓÎÀë"
]),
([      "action" : "$NÊ¹³öÒ»ÕĞ¡ºĞÇ¹â¶ÙÃğ¡»£¬Ç°½ÅÒ»¶å£¬Ëæ¼´·­Éí¶øÆğ£¬ÊÖÖĞ$w²»´øË¿
ºÁ·çÉùÈ´ÓÖÑ¸ËÙÎŞ±ÈµØÉäÏò$nµÄÇ°ĞØ",
    "damage": 120,
    "dodge" : 90,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 72,
    "skill_name" : "ĞÇ¹â¶ÙÃğ"
]),
([      "action" : "$NÍ»È»ÌÚÉíÏòºó¼±ÍË£¬Ê¹³ö¡ºĞÇ¿ÕÕ¨À×¡»£¬Ë«ÊÖÏòÇ°Ò»ÍÆ£¬ÊÖÀï$w¾Í
ÒşÒş´ø×ÅÀ×Éù¼²ÉäÏò$n",
    "damage": 140,
    "dodge" : 95,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 81,
    "skill_name" : "ĞÇ¿ÕÕ¨À×"
]),
([      "action" : "$NÊ©Õ¹³ö¡º"+HIW"ĞÇ»®³¤¿Õ"NOR+"¡»£¬Ô­µØ²àÉí·ÉÆğ£¬ÓÒÊÖÎ¢Î¢ÏòÇ°Ò»È÷£¬ÊÖÖĞ$w
»Ã×÷Ò»µãº®¹â³ÊÔ²»¡ĞÎÉäÏò$n",
    "damage": 160,
    "dodge" : 100,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 90,
    "skill_name" : "ĞÇ»®³¤¿Õ"
]),
([      "action" : "$NÎ¢Î¢ÄıÉñ£¬Ê¹³ö¡º"+HIY"ĞÇ¹âÍòÕÉ"NOR+"¡»£¬ÉíÓ°Æ®ºö²»¶¨£¬$n¶Ù¾õÊ®·Ö´ÌÑÛ£¬È´
¼û$NÊÖÀïµÄ$wÒÑĞ®×ÅµØÉÏµÄÉ³Ê¯ÒÔ¼°ÖÜÎ§µÄÊ÷Ò³¹¥Ïò×Ô¼º",
    "damage": 190,
    "dodge" : 105,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 99,
    "skill_name" : "ĞÇ¹âÍòÕÉ"
]),
([      "action" : "$NºöÈ»ÇáÌ¾Ò»Éù£¬×ªÉí¶øĞĞ£¬$nÕı³ÙÒÉ¼ä£¬È´¼ûÑÛÇ°ÒÑ¾¡ÊÇ$wµÄÓ°×Ó£¬
ÑÛ¿´ÎŞ´¦¿É¶ãÁË£¡Ö»ÅÂÕâÕĞ¾ÍÊÇ¡º"+HIC"ÂúÌìĞÇÓê"NOR+"¡»ÁË£¬$n²»ÓÉ´ó¾ªÊ§É«",
    "damage": 220,
    "dodge" : 110,
    "post_action":  (: call_other, "/adm/daemons/weapond", "throw_weapon" :),
    "damage_type" : "´ÌÉË",
    "lvl" : 110,
    "skill_name" : "ÂúÌìĞÇÓê"
])
});

int valid_enable(string usage) { return usage=="throwing" ||usage=="dodge"||usage=="parry"; }

int valid_learn(object me)
{
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("ÄãµÄÄÚ¹¦ĞÄ·¨»ğºò²»¹»£¬ÎŞ·¨Ñ§ÂúÌìĞÇ¡£\n");
    if ((int)me->query_skill("dodge", 1) < 20)
   return notify_fail("ÄãµÄÇá¹¦»ğºò²»¹»£¬ÎŞ·¨ÁìÎòÂúÌìĞÇ¡£\n");
    if ((int)me->query_dex() < 25)
   return notify_fail("ÄãµÄÉí·¨²»¹»ÁéÇÉ£¬ÎŞ·¨ÁìÎòÂúÌìĞÇ¡£\n");
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
    int i, level;
    level = (int)me->query_skill("mantian-xing", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    object weapon;
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "throwing")
   return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
    if ((int)me->query("qi") < 30)
    return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË¡£\n");
    if ((int)me->query("neili") < 30)
   return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·ÂúÌìĞÇ¡£\n");
    me->receive_damage("qi", 30);
return 1;
}
string perform_action_file(string action)
{
    return __DIR__"mantian-xing/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    if( random(me->query_skill("mantian-xing",1)) > 50) {
    victim->apply_condition("anqi_poison", random(2) + 1 +
   victim->query_condition("anqi_poison"));
    }
}

