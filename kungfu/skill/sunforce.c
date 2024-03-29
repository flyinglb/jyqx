// sunforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("光明神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return "/daemon/skill/sunforce/" + func;
}

int protect(object me, object who, int damage_bonus)
{
	int protect_factor, count;

	protect_factor = me->query_skill("sunforce");

	if ( protect_factor	&& me->query("force") > 30
	&& random(protect_factor) > 10 ) {
		count = protect_factor + random(protect_factor);
		protect_factor = protect_factor * protect_factor /5;
		count += random(protect_factor);

		if( count >= damage_bonus )
			tell_object(me, "你成功地运用光明神功的护体真气化解了对方的伤害！\n"); 
		if( count >= damage_bonus/2 && count < damage_bonus )
			tell_object(me, "你成功地运用光明神功的护体真气化解了对方大部分的伤害！\n");                              
		if( count < damage_bonus/2 && count > 0 )
			tell_object(me, "你成功地运用光明神功的护体真气化解了对方一部分的伤害！\n");                              

		me->add("force",-30);
	}

	return -count;
}
 
int enable_factor() { return 20; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 15; }