// Room: /d/songshan/luyanpubu.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "«���ٲ�");
	set("long", @LONG
����ˮ�����ף��ͱ�����������ֱ��������˫�ٲ�й������
��������Ծ���ݣ�ˮ��ӳ�գ�����������
    �ٲ�һ����һСС«���£��ٲ�б������ʤ�۷塣�ٲ�֮��
��·���ϡ�
LONG );
	set("exits", ([
		"southwest" : __DIR__"shandao1",
		"up"        : __DIR__"tieliang",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	setup();
}
 
int valid_leave(object me, string dir)
{
    if ((random((int)me->query_skill("dodge")) <= 20) && dir=="up")    
    {
        return notify_fail("��ʹ����һ�ģ����ٲ�����������Զ�͵���������ˤ�ı������ס�\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 35) && dir=="up")    
    {
        return notify_fail("�����һԾ��ȴ���ٲ�������һ�ɶ�Զ�������ǰ׷�������\n");
    }
    if ((random((int)me->query_skill("dodge")) <= 60) && dir=="up")    
    {
        return notify_fail("������������ٲ���ֻ��һ����ˣ��ټӰѾ���\n");
    }

    return ::valid_leave(me, dir);
}

