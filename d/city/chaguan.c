// Room: /d/city/chaguan.c
// Created by Eatdami@MX

inherit ROOM;

string *discard_cmds =({"sleep","respitate","jingzuo","array","duanlian","ansuan",
                        "touxi","persuade","teach","exert","exercise","study",
                        "learn","kill","steal","conjure","fight","hit","perform",
                        "practice","research","lian","tuna","yun","du","dazuo"});
void create()
{
	set("short", HIM"�������"NOR);
	set("long", @LONG
����ǽ��������Ĵ�����ݡ�����ľ���û�µ�ʱ�����������
�����������ƹʺ�ҥ�ԡ���һ�߽��������ŵ�һ�ɲ���������Ƣ������
Ϊ֮һˬ�����Ű�����һ���ſ��������˿��ˣ������̸Ц����ͷ��
���������Ǽ������ҡ�
LONG );
	set("resource/water", 1);
	set("exits", ([
		"east"  : __DIR__"nandajie2",
		"west"  : __DIR__"chaguan1",
		"south" : __DIR__"chaguan2",
		"north" : __DIR__"chaguan3",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
		__DIR__"npc/baixiaosheng" : 1,
	]));

	set("valid_startroom","1");
        set("no_fight","1");

	setup();
        "/clone/board/player_b"->foo();
}

void init()
{
    if (wizardp(this_player()))
        return;
    add_action("discard",discard_cmds);
}

int discard()
{
        tell_object(this_player(),"��������Ϲ�����ˡ�\n");
        return 1;
}

int valid_leave(object me, string dir)
{
//        if( (dir=="south" || dir=="north" || dir=="west") && !wizardp(me) ) {
//                tell_object(me,HIR"�˴�������ʱ������ˣ������ȥ��\n"NOR)
        if( (dir=="south" || dir=="north" || dir=="west") && !userp(me) )
                return 0;
//        }
        return ::valid_leave(me, dir);
}

