//Room: /d/dali/luojiadian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��٤��");
	set("long",@LONG
�����ǵ�صĶ��ϣ���ôЩ������٤����۾ӵĵط���ôЩ����
�����ġ�����ϲ��ƽԭ��ˮ������ˮ��ƽԭ���ӣ���Ϊ���顱������
���������֣���ȱ��ס���٤��һ�����䣬��٤���Ǹ��൱�����
�ӣ�����������������θ���
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : __DIR__"yanchi3",
	    "southwest"  : __DIR__"yanan1",
	    "east"       : __DIR__"nongtian2",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

