//ROOM: shanjiao.c

inherit ROOM;

void create()
{
	set("short", "��翷�ɽ��");
        set("long",@LONG
��������翷�ɽ��, ̧ͷ����, ��翷���������, �嶥��������, ��
���ɾ�. �������Լ�ɼ���¥����, �Ǿ��������������ɥ���ġ���
�չ�������˵����ס��һЩ���ո�ǿ��Ů��, ����ֻ��Ů����Ϊͽ��
LONG
        );
        set("outdoors", "lingjiu");
	set("exits", ([
		"westup" : __DIR__"ya",
		"southdown" : "/d/xingxiu/tianroad2"
        ]));
	set("objects",([
		__DIR__"npc/jiuyi" : 1,
       	]));
//	set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
