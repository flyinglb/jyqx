// houhuayuan.c ��Է

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
                "west" : __DIR__"houhuayuan2",
                "south" : __DIR__"qihedian",
        ]) );
        set("objects", ([
                "/d/huanggon/npc/gonnv" : 2,
        ]) );
        setup();
        replace_program(ROOM);
}
