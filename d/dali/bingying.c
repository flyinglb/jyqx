//Room: /d/dali/bingying.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","��Ӫ");
	set("long",@LONG
�������С��ȴ���Ӿ���������Ȼ���˱�����־������������֮
�ߣ����ϴ������뱱���γ��޺ͣ�����������£�����ˣ�������ս�¡�
���ǳ��������Ӫ��Ϊ����ĵ�ϵ��װ�������޲�������ԭ�ط�����
ʿ�������Դ�����������������������
LONG);
	set("objects", ([
	   __DIR__"npc/bing": 2,
	   __DIR__"npc/weishi1": 1,
	]));
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"dahejiewest",
	    "west"   : __DIR__"majiu",
	]));
	setup();
	replace_program(ROOM);
}

