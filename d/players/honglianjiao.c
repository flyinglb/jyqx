// Room: /d/players/honglianjiao.c

inherit ROOM;

void create()
{
        set("short", "�����̻�");
	set("long", @LONG
������Ǻ����̴������ĵط�,������������Կ����������̡�������
����������Ĵ�Բ���϶������������˵�����,��һд���ڵĻ㱨��¼������
���ڽ�������Ծã�����������Ϊ�¾�.����ɨ��ʮ�ָɾ��ıڹ���һЩ����
�黭��Ʒ����Ϊ�ϳ�֮��������һ���黭�����ź����̵���ּ(paper)
LONG );
	set("exits", ([
                "north" : "/d/foshan/road10",
	]));
         set("objects",([
                 __DIR__"npc/honglianjiao" : 2,
        ]));
        set("item_desc", ([
 "paper" : "    �����̵ĳ���Ψһ��Ŀ�����Ž����� MUD ����������õ���Ϸ�˼䡣\n"
"��������� PKER �������������ʱ���������ĵ�����ʵ�ڲ���ô������\n"
"��������̵���ҽ���ĸ��˽�����������ʹ�����ȫ��̤�ϴ���֮·�Ա�\n"
"�Ժ���ά�ֽ�ӹ�����壡\n",
        ]));
        set("valid_startroom", 1);
        set("no_fight", "1");
          setup();
//          "/clone/board/honglianjiao"->foo();
	replace_program(ROOM);
}

