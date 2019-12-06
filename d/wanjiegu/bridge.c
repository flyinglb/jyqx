// Room: /t/wanjiegu/bridge.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
һ��������׽��������ţ����Ź����ĵ��������������£���
��ľ�壬�Թ����ߣ��������ԣ���Ϊ���֡�һ̤���ţ�����������
���ζ�����ˮ������������ڴӽŵ׷ɹ���ֻҪһ��ʧ�㣬����
��ˮ�������õ�ˮ��Ҳ�ѻ�����
LONG
        );
        set("outdoors", "wanjiegu");
        set("exits", ([ /* sizeof() == 2 */
            "west" : __DIR__"port2",
            "east" : __DIR__"port",
        ]));
        set("no_clean_up", 0);

        setup();
}

int valid_leave(object me, string dir)
{
//        object *inv, ob;
        object *inv;
        int i;

        if(wizardp(me)) return 1;

        switch( random(5) ) {
            case 0: inv = all_inventory(me);
                    if( !sizeof(inv) ) {
                        message_vision(HIW "$N�����ϻ���һ�£�����������ӿ����
�׽��У�\n" NOR,me);
                        return notify_fail("");
                    } else {
                        i = random ( sizeof(inv) );
                        if(! inv[i]->query("no_drop")) {
                           message_vision(HIW "$N������һ�Σ����ϵ�"
+inv[i]->name()+"���������׽�֮�У�\n" NOR,me);
                           destruct(inv[i]);
                           return notify_fail("");
                        }

                    }
            case 1:
            case 2:  message_vision( HIW "$N�����ϻ���һ�£�����������ӿ������
���У�\n" NOR,me);
                     return notify_fail("");
            default: return 1;
        }
}

