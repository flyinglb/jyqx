
// Room: fuheqiaoe.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short","������");
	set("long",@LONG
�����ǳɶ������⸮���š��ɶ��Թž��Ǵ����׸������Ӻ��Ϻ�
�гǶ�������Ϊ��Ȼ�Ļ��Ǻӡ������Ĵ�����Ͽ��������֮�գ�����
������֮�̣��ɶ�ȴ��֮���������سɹ�֮���������������£���
��߳��ˡ�
LONG);
	set("outdoors", "chengdu");
	set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"road2",
            "west"  : __DIR__"eastgate",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

