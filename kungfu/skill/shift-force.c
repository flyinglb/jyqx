// shiftforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("乾坤大挪移心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
       return "/kungfu//skill/shift-force/" + func; 
}

int protect(object me, object who, int damage_bonus)
{
	int protect_factor, count;
	object *enemy, ob;

	enemy = me->query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob)	return 0;

	protect_factor = me->query_skill("shift-force");

	if ( protect_factor	&& me->query("force") > 30
	&& random(protect_factor) > 15 ) {
		count = protect_factor + random(protect_factor);
		protect_factor = protect_factor * protect_factor /10;
		count += random(protect_factor);

		if(ob != who
	 	&& random(me->query("combat_exp")) > random(ob->query("combat_exp")) ) {
			tell_object(me,
"你施出乾坤大挪移心法把" + who->name() + "的攻击转移到" + ob->name() +"身上！\n");
			tell_object(ob,
me->name() + "不知使出什么武功把" + who->name() + "的攻击转移到了你的身上。\n");
			ob->receive_damage("kee", count);
			COMBAT_D->report_status(ob, 0);
		}	

		if( count >= damage_bonus )
			tell_object(me, "你成功地运用乾坤大挪移心法化解了对方的攻击！\n"); 
		if( count >= damage_bonus/2 && count < damage_bonus )
			tell_object(me, "你成功地运用乾坤大挪移心法化解了对方大部分的攻击！\n");
		if( count < damage_bonus/2 && count > 0 )
			tell_object(me, "你成功地运用乾坤大挪移心法化解了对方一部分的攻击！\n");

		me->add("force",-30);
	}

	return -count;
}

int enable_factor() { return 18; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 13; }
