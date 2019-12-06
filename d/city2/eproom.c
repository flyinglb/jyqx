// pigtest room

#include <pig.h>

inherit "/inherit/room/pigroom";

string look_table();
string look_scoreboard();
string look_rules();

void create()
{
	set("short", "����");
	set("long", @LONG
	����һ��ר��Ϊ������ر���ƵĹ�������������ƻ�ͨ�����·���
Զ׼����Ϊ������Ƿ����Ƶġ���������ķ���һ���ð���������ľ�����ƵĹ�
����(table)����Χ�����İ��ľ�����Ρ������ϰ���һ���Ƿֲ�(scoreboard)��
���ߵ�ǽ������һ��ֽ(paper)��
LONG );
	set("pigging", 1);

	set("item_desc", ([
		"table" : (: look_table :),
		"scoreboard" : (: look_scoreboard :),
		"paper" : "����ض� help pig_cmds �� help pig_rules��\n",
	]));
	set("exits", ([
		"west": "/d/city2/duchang2",
	]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	setup();
}

string look_table()
{
	if (this_player()->query_temp("pigging_seat"))
		return table_str(this_player()->query_temp("pigging_seat"));
	return table_str("");
}

string look_scoreboard()
{
	return scoreboard_str();
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("pigging_seat"))
		return notify_fail("���뿪�����������ж���\n");
	return ::valid_leave(me, dir);
}
