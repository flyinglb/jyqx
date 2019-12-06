// room: /d/xingxiu/tianroad6.c
// Jay 3/18/96

inherit ROOM;
#include <ansi.h>;
string look_wind();
int lian(string arg);
void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
��������ɽ���塣����������Χ��ȥ�����׶���ԭ�ķ�⾡���۵ס�����
һ��С·������ɽ��ɽ��(wind)��������Ϊǿ���������޷�վ����
LONG
        );
        set("exits", ([
            "eastdown" : __DIR__"tianroad5",
        ]));
        set("item_desc", ([
            "wind" : (: look_wind :),
        ]));
        set("objects", ([
               __DIR__"npc/snake" : 2, 
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
}

string look_wind()
{
	return
"����һ�굽ͷ����ֹЪ�����Լ����麣�����磬����ζ���\n"
"�����ǳ���\n";
}
void init()
{
	add_action("lian", "lian");
	add_action("lian", "practice");
}

int lian(string arg)
{
	string skillname;
	int skill, skill_basic, times, pertimes;
	object me=this_player();
	if (!arg)
        {
		write("��Ҫ��ʲô�书��\n");
                return 1;
        }
	if ( (sscanf(arg, "%s %d", arg, times)!=2 ))
		return notify_fail("ָ���ʽ��practice|lian <��������> <����>\n");
	if ( times < 1 || times > 30)
		return notify_fail("��ϰ�����������һ�Σ������ܳ�����ʮ�Ρ�\n");
	if (arg!="blade")
        {
		write("���Ƶ�����û���������书��\n");
                return 1;
        }
	if (me->is_busy())
		return notify_fail("��������æ���ء�\n");
	if( me->is_fighting() )
		return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");
	if( !stringp(skillname = me->query_skill_mapped(arg)) )
		return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

	for (pertimes = 1; pertimes <=times ; pertimes ++)
	{
		skill_basic = me->query_skill(arg, 1);
		skill = me->query_skill(skillname, 1);
		if( skill < 1 )
		return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
		if( skill_basic < 1 )
		return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");
		if( skill_basic/2 <= skill/3 )
		return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

		notify_fail("�����ڲ�����ϰ����ܡ�\n");
		if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

		notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
		if (skill*skill*skill/10 > (int)me->query("combat_exp")) 
		{
			return notify_fail("Ҳ����ȱ��ʵս���飬�����ϰ��û��������\n");
			return 1;
		}

		if( SKILL_D(skillname)->practice_skill(me) )
		{
			me->improve_skill(skillname, skill_basic/2 +1, skill_basic > skill? 0: 1);
			write(HIY"�������Ƶ������ƣ����"+to_chinese(skillname)+"���н����ˣ�\n"NOR);
		}
		else return 0;
	}
}
