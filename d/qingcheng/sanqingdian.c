// Room: /qingcheng/sanqingdian.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
�ų����۵��������������й����������������ԭʼ����
�����鱦�����̫��̫���Ͼ���ԭʼ��������Բ�飬������Ԫ����
�����𻳱�̫��ͼ��������Ԫ��̫���Ͼ��ֳ����ӣ�����̫������
����һ����(lian)����ī��Ũ��
LONG );
	set("exits", ([
		"south"    : __DIR__"tianshidong",
	]));
	set("item_desc", ([
		"lian"    : 
"\n
     һ      ��
     ��      ��
     ��      ��
     ��      ��
     ��      ��
     ��      ��
     ��      ��
     ��      ��
     ��      ��
     ��      Ȼ
\n",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

