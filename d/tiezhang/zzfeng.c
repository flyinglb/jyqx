// Room: /u/zqb/tiezhang/zzfeng.c

inherit ROOM;

void create()
{
	set("short", "��ָ��");
	set("long", @LONG
    �����������ɽ����߷�--��ָ�塣����ɽ��̫�ߣ��嶥�Դ���
�����Ļ�ѩ����ѩ������������������£�����һƬҫ�۵����⡣��ĿԶ
�������������ﾰɫ�����۵ף���Ϫ����Ϫ�������������ɽ�»�������
��Զ��������ɫ�����ߣ����������Ĵ�--�佭��
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"shanlu-9",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

