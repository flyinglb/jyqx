// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��������" NOR,
	HIB "������" NOR,
	HIB "�������" NOR,
	CYN "�������" NOR,
	CYN "����似" NOR,
	CYN "�����뻯" NOR,
	HIC "�Ƿ��켫" NOR,
	HIC "һ����ʦ" NOR,
	HIW "��ɲ�" NOR
});

string *knowledge_level_desc = ({
	BLU "��ѧէ��" NOR,
	HIB "�����ž�" NOR,
	HIB "��֪һ��" NOR,
	HIB "������" NOR,
	HIB "����С��" NOR,
	CYN "�������" NOR,
	CYN "��Ȼ���" NOR,
	CYN "��Ȼ��ͨ" NOR,
	HIC "������˫" NOR,
	HIC "������" NOR,
	HIW "��ɲ�" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
	object ob, man, *all;
	mapping fam, skl, lrn, map;
	string *sname, *mapped;
	int sp, dp;
	int i, cost, check_level;

	seteuid(getuid());

	all = all_inventory(environment(me));
	for(i=0; i<sizeof(all); i++) {
		if( living(all[i]) && !userp(all[i]) ) man = all[i];
	}

        if ( (!(fam = me->query("family")) || fam["family_name"] != "ؤ��") )
		return notify_fail("ֻ����ؤ���ܴ�̽���˵ļ��ܣ�\n");

	if ( !objectp(man) )
		return notify_fail("��Χû���ܰ���ȥ�˽���˵ļ��ܣ�\n");

        if ( me->query_skill("checking",1) < 10 )
		return notify_fail("��Ĵ�̽������δ���죬�޷��˽���˵ļ��ܣ�\n");

	if ( !arg )
		return notify_fail("��Ҫ����˭�ļ��ܣ�\n");

        if ( present(arg, environment(me)) )
		return notify_fail("��Ҫ�������˾��ڱ��ϣ��������ʲ����׵��ɣ�\n");

	ob = find_player(arg);
	if (!ob) ob = find_living(arg);
	if (!ob) return notify_fail("��Ҫ����˭�ļ��ܣ�\n");

	if ( ob == me )
		return notify_fail("��û���᱿�ɣ�Ҫ���˸������Լ��ļ��ܣ�\n");

	cost = me->query("max_jing")/(me->query_skill("checking",1)/10) - 10;

	if ( me->query("jing") <= cost )
		return notify_fail("������̫���ˣ��޷�ȥ�������˵ļ��ܡ�\n");

	tell_object(me, "������ǰȥ��С���������" + man->name() + "��������" + ob->name() + "����� ...\n\n");
	message("vision", "ֻ��" + me->name() + "����Ц����" + man->name() + "˵�Ż��������ڴ���Щʲô��\n\n", 
		environment(me), ({ me, man }) );

	sp = me->query_skill("checking")*10 + me->query("kar")*5 + me->query("jing") + man->query("jing");
	dp = ob->query("kar")*5 + ob->query("jing")*2;
	
	if ( random(sp) < random(dp) || ob->query("id") == "princess")
		return notify_fail( man->name() + "ҡ��ҡͷ��˵���������ҿɲ������"
		 	+ RANK_D->query_respect(me) + "����ȥ����˴���һ�°ɣ�\n");

	me->receive_damage("jing", cost );

	skl = ob->query_skills();
	if(!sizeof(skl)) {
		write( man->name() + "�����㣺 " + ob->name() + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
		return 1;
	}
	write( man->name() + "�����㣺 " + ob->name() +"Ŀǰ��ѧ���ļ��ܣ�\n\n");
	sname  = sort_array( keys(skl), (: strcmp :) );
	
	map = ob->query_skill_map();
	if( mapp(map) ) mapped = values(map);
	if( !mapped ) mapped = ({});

	lrn = ob->query_learned();
	if( !mapp(lrn) ) lrn = ([]);
	
	i = random(sizeof(skl));

	printf("%s%s%-40s" NOR " - %-10s %3d/%5d\n", 
		(lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : "",
		(member_array(sname[i], mapped)==-1? "  ": "��"),
		to_chinese(sname[i]) + " (" + sname[i] + ")",
		skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
		skl[sname[i]], (int)lrn[sname[i]],
	);
	check_level = me->query_skill("checking", 1);
	if ( (int)me->query("combat_exp") > (check_level*check_level*check_level)/10)
	{
		me->improve_skill("checking", random(me->query("int")));
	}

	write("\n");
	return 1;
}

string skill_level(string type, int level)
{
	int grade;

	grade = level / 20;

	switch(type) {
		case "knowledge":
			if( grade >= sizeof(knowledge_level_desc) )
				grade = sizeof(knowledge_level_desc)-1;
			return knowledge_level_desc[grade];
		default:
			if( grade >= sizeof(skill_level_desc) )
				grade = sizeof(skill_level_desc)-1;
			return skill_level_desc[grade];
	}
}

int help(object me)
{
	write(@HELP
ָ���ʽ : check|dating [<ĳ��>]

���ָ������������������ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills|cha ���Բ�֪�Է��ļ���״����

������Ϊؤ�����ר�ã�����ѧϰ��Ӧ�ļ��ܡ�

HELP
    );
    return 1;
}
