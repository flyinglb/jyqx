//Room: /d/dali/neitang.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
�������������������á�ʮ�ֿ�������������ǽ�Ϲ���һ��ˮī
�������߸���һ�����ӣ�͸���������Կ����������ɽ��ˮ��
LONG);
	set("objects", ([
	    CLASS_D("dali")+"/duanzc": 1,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"yongdao2",
	]));
	setup();
	replace_program(ROOM);
}
