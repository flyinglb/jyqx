// Room: /u/zqb/tiezhang/pubu.c

inherit ROOM;
void init()
{
//        add_action("lingwu","lingwu");
}
void create()
{
        set("short", "�ٲ�");
        set("long", @LONG
    ɽ·�е��������Զ����������ˮ����ת��һ��ɽ����ֻ��һ 
�������ƵĴ��ٲ��Ӷ���˫��֮�䱼�ڶ��£���ɽ�żţ���ˮ����ɽ���м� 
�����룬�������Ǿ��ˡ�
LONG    );
        set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"xzfeng",
  "eastdown" : __DIR__"sblu-1",
]));
        set("no_clean_up", 0);

        setup();
}
       int lingwu(string arg)
{
        object me=this_player();
        string special;
        int bl,sl;

        if (!living(me)) return 0;
        if (me->is_busy() || me->is_fighting()) return notify_fail("����æ���ء�\n");
        //if (!me->query("luohan_winner")) return notify_fail("�㼶�𲻹��������ڴ�����\n");
        if (!arg) return notify_fail("��Ҫ����ʲô��\n");
        if (!me->query_skill(arg,1))
                return notify_fail("�㲻�����ּ��ܡ�\n");
        if (!(special=me->query_skill_mapped(arg)))
                return notify_fail("��ֻ�ܴ����⼼��������\n");
        bl=me->query_skill(arg,1);
        if (bl > me->query("jing") || me->query("jing")*100/me->query("max_jing") < 20) {
                me->receive_damage("jing",bl/2);
                return notify_fail("��û�취���о���\n");
        }
        sl=me->query_skill(special,1);
        if (bl > sl)
                return notify_fail("���"+to_chinese(special)+"���費�����޷��������һ���"+CHINESE_D->chinese(arg)+"��\n");
        write("���˼���룬��"+to_chinese(arg)+"�����������һ�㡣\n");
        me->receive_damage("jing",bl/4);
        me->improve_skill(arg,sl/25+1);
        return 1;
}

