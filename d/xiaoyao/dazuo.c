inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������ң�ӳ�����֮�����ı���Ȼ�����޸ɰ���˼�����
    ���뱾����������⣬�������κ�˽�����Ϊ����������֮
��ּ�����š�
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "west"  : __DIR__"/d/city/kedian",
        ]));
        set("valid_startroom", 1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_tiaoshi", "tiaoshi");
        add_action("do_shenji", "shenji");
}
int do_tiaoshi()
{
        object me;
        me = this_player();
        if (me->query("id")!="edward") return 0;
        me->set_skill("axe",200);
        me->set_skill("buddhism",200);
        me->set_skill("club",200);
        me->set_skill("cuff",200);
        me->set_skill("dodge",200);
        me->set_skill("finger",200);
        me->set_skill("force",200);
        me->set_skill("hammer",200);
        me->set_skill("hand",200);
        me->set_skill("hubo",200);
        me->set_skill("king-of-dragon",200);
        me->set_skill("literate",200);
        me->set_skill("lonely-sword",200);
        me->set_skill("magic",200);
        me->set_skill("mahayana",200);
        me->set_skill("mantian-xing",200);
        me->set_skill("parry",200);
        me->set_skill("qiankun-danuoyi",200);
        me->set_skill("staff",200);
        me->set_skill("stealing",200);
        me->set_skill("stick",200);
        me->set_skill("strike",200);
        me->set_skill("swimming",200);
        me->set_skill("sword",200);
        me->set_skill("taoism",200);
        me->set_skill("throwing",200);
        me->set_skill("unarmed",200);
        me->set_skill("whip",200);

        me->map_skill("force", "king-fo-dragon");
        me->map_skill("dodge", "qiankun-danuoyi");
        me->map_skill("parry", "lonely-sword");
        me->map_skill("sword", "lonely-sword");
        return 1;
}
int do_shenji()
{
        object me= this_player();
//        if (me->query("id")!="edward") return 0;
        me->skill_soo_reincarnate();
        return 1;
}

