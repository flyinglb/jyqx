// Room: /d/mingjiao/shanlu1.c
// Date: Java 97/04/9

inherit ROOM;

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
 �������ǰ�ɽ���ˡ���Զ��ǰ����һ����ͤ����λ������
����ЪϢ��ɽ·��������Ӷ��ͣ�������ȥ�����͵��֣���Ŀ
�δ�Զɽ����װ���ƺ�����ۡ�
LONG );
	set("exits", ([
		"eastdown" : __DIR__"shanmen",
		"westup" : __DIR__"shanlu2",
	]));
        set("objects",([
              "/d/taishan/npc/dao-ke" : 2,
        ]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	setup();
	replace_program(ROOM);
}

