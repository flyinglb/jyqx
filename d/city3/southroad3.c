// Room: southroad3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������ϴ�ּ�ʵ����ʯ������ϣ���ɫ�˵��������У�������
�֡���ʱ����ܻ����һЩ����װ����������ǿ������죬����Ҳ
�廨���ţ��������������㣬�ɲ��Ǻ��ǵġ����������Ĵ��������
��֡����Ϸ��Ǹ���Ρ��Ľ���Ⱥ���˽��˳���ʮ�����֡�����ͨ��
����֡�
LONG );
        set("outdoors", "chengdu");
	set("exits", ([
	    "northwest"  : __DIR__"westroad1",
	    "southwest"  : __DIR__"wuhoucigate",
	    "east"       : __DIR__"southroad2",
	]));
	set("objects", ([
	    "/d/taishan/npc/jian-ke": 2,
	    "/d/taishan/npc/dao-ke" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
