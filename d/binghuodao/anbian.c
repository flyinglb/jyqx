#include <ansi.h>

inherit ROOM;

void rtaohua( object ob ) ;

void create()
{
    set("short", "���𵺺�̲");
    set("long", @LONG
���𵺵ĺ�̲����һ������ĵ��졣�����������Ǽ�ʯ��᾵�ɽ��
���ι�����Ī����״������ȴ��һ��������ͷ��ԭҰ���ô���Ȼ�ؽ���
���������ɽ���겻�𣬵��������ͳ���ɽ��������һ�����ƣ���ɽ
��������ѩ���ݵ���ȴ��Ŀ���̣����ɴ�أ��ߴ��쳣����������滨
��������Ϊ�������ޡ�
LONG );
    set("outdoors", "binghuodao");
set("exits", ([
"north" : __DIR__"road1",
]));
    setup();
}


