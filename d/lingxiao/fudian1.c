//LUCAS 2000-6-18
// Room: fudian1.c

inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
�����������ǵĸ���֮һ��ѩɽ��������ӣ������Ű�����
�⣬������֧����֧����Լ���ϵ����ʲô�£����ֲ����ᵽȫ
�ɽ���ģ��������ڸ������顣
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "west"  : __DIR__"lianwu1",
            "east"  : __DIR__"dadian",
        ]));
        set("objects", ([
               "/d/lingxiao/npc/dizi" : 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

