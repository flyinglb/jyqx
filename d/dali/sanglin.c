//Room: /d/dali/sanglin.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","ɣ��");
	set("long",@LONG
һ��Ƭɣ���������ڵ�ɽ�Ļ���ɽ���ϡ����ϡ���˿�ǰ������
��Ҫ��ҵ�����ĸ�Ů����֯˿����֯�Լ����ŵĶ�ȹ��Ҳ��������
"�����佻��Щ������Ʒ��һȺ���Ĺ��������ּ�æ�Ų�ժɣҶ��
LONG);
	set("objects", ([
	   __DIR__"npc/caisangnu": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "northdown"  : __DIR__"yangzong",
	]));
	setup();
	replace_program(ROOM);
}

