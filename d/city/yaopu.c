// Room: /city/yaopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "ҩ��");
	set("long", @LONG
����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С
������ɢ�������ġ���ҽƽһָ���ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�
һ��С���վ�ڹ�̨���к��Ź˿͡���̨������һ�ŷ��ƵĹ��(guanggao)��
LONG );
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
�޳������һ�����ҩʦ���䣬������ǣ�
�쾦�����ΰٶ�����Ч������
������ҩ���ϰ����顣\n",
	]));
//	set("item_desc", ([
//		"guanggao" : "�����ϰ�ƽһָ�����ҩδ�飬������ͣӪҵ��\n",
//	]));
	set("objects", ([
		__DIR__"npc/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"dongdajie2",
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

