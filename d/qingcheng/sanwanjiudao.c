// Room: /qingcheng/sanwanjiudao.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "����ŵ�");
	set("long", @LONG
ɽ��Խ��Խ���ͣ�ʯ�ݼ����������չ�����ͤ��ԶԶ�������
ɽ�ۣ���̨ɽ֮���ķ������ߣ����幬���ˡ�
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"southdown"  : __DIR__"chaoyangdong",
		"eastup"    : __DIR__"shangqing",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

