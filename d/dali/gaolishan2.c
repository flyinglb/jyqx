//Room: /d/dali/gaolishan2.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����ɽ����");
	set("long",@LONG
����ɽ�ϵ����ն�����������������������̡��ش���ɽ��
���Ժ����ܻ�������ʱ����û��ֻ���¸ҵ����˲Ÿ���������������
��ɽ������ˮ�ȵء�
LONG);
	set("objects", ([
	   "/d/hangzhou/npc/laohu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"gaolishan1",
            "west"  : "/d/wudujiao/cun9",
	]));
	setup();
	replace_program(ROOM);
}

