// Room: /city/lichunyuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "����Ժ");
	set("long", @LONG
��һ�߽�����һ�۾Ϳ���������ǽ�Ϲ���һ��������ͼ(tu)��һ���Ӿ�
����������ʲô�ط������ڵ����ŵƽ�ʣ������˱ǡ�����������������
��Ů�˷�վ���Զ��㷢����Ц������Τ�����������¡�ǰǰ����к��ſ��ˡ�
��¥�ϴ���������������ε�������
LONG );
	set("objects", ([
                CLASS_D("gaibang") + "/kongkong" : 1,
                __DIR__"npc/wei" : 1,
                "/d/city2/npc/mao18" : 1, 
	]));

	set("item_desc", ([
		"cannotsawtu" :
"                                      ��        ��          ��             
                                    ����        ��          ��
      ����������  ���С�����        ����      ����          ����
    ����������    ����������  ����������  ������ء�  �������ة�


   ��       ��    ������                 ��                  ��
   ��       ��    ������       ������  ����                  ��
   �� ���Щ���    �����ੴ   ��������������          ��С�����
   ��   ������    ��  ��                 ��            ��  ����
	\n"]));
	set("exits", ([
		"west"  : __DIR__"nandajie2",
		"up"    : __DIR__"lichunyuan2",
//		"north" : __DIR__"library",
	]));

//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

