// houhuayuan2.c ��Է

inherit ROOM;

void create()
{
        set("short", "��Է");
        set("long", @LONG
�����ǻ����ͻ��ĺ�Է.ƽ�������ʱ���������,�͹�������
һ���ͻ�Ʒ��.����,�����ƽ��̫��,������������.����Ĺ�Ů����
��������,��ͨ������.�����Ĺ�,��Ŀ�����ƽ�����,����ϸ�ֱ�,��
ȻƷĿ��ȫ,������õ�,�������붼�������,���ﶼ����.�㲻��
��Щ�ʼ���ʵ��϶���.
LONG
);
        set("outdoors", "huanggon");
        set("exits", ([
                "east" : __DIR__"houhuayuan",
                "west" : __DIR__"majuan.c",
        ]) );
        set("objects", ([
                "/d/huanggon/npc/gonnv" : 2,
        ]) );
        setup();
        replace_program(ROOM);
}
