// Room: /d/xiangyang/guofuyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "������Ժ");
	set("long", @LONG
�����ǹ����Ĵ�Ժ������һ�¿����İ����ձڣ����顰��
�ı������ĸ����֣�������һɫ����ש�̵أ��������˼��ô�
�����м�����������Ժ����ɨ�������ǹ����Ŀ���,��
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"guofugate",
		"north" : __DIR__"guofuting",
	]));
	setup();
	replace_program(ROOM);
}

