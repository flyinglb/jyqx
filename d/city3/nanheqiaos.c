
// Room: nanheqiaos.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short","�Ϻ���");
	set("long",@LONG
�����ǳɶ��������Ϻ��š����Ӻ��ϺӼг���������Ϊ��Ȼ�Ļ�
�Ǻӣ�����������츮֮���Ĵ����׸����򱱾ͽ����ˣ���������һ
��С·��
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
            "south"  : "/d/xuedao/sroad1",
            "north"  : __DIR__"southgate",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

