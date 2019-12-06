// huangzhen.c
inherit NPC;
inherit F_BANKER;
#include <ansi.h>;
void create()
{
        set_name("����", ({"huang zhen", "zhen", "huang"}));
        set("nickname", HIY"ͭ��������"NOR);
        set("no_beg_from", 1);
        set("no_get_from", 1);
        set("no_steal_from", 1);

        set("gender", "����");

        set("age", 59);
        set("long",
                "����������Գ������Ŀ��Ŵ���ӣ�Ҳ�����Ǯׯ���ϰ壬�����������á�\n");
        set("attitude", "peaceful");
        set("per", 21);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 30);

        set("max_qi",2500);
        set("max_jing",1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);

        set("combat_exp", 300000);
        set("shen_type", 1);

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("strike", 80);
        set_skill("cuff", 80);
        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("literate", 100);

        set_skill("huashan-sword", 80);
        set_skill("zixia-shengong", 80);
        set_skill("poyu-quan", 80);
        set_skill("hunyuan-zhang", 80);
        set_skill("feiyan-huixiang", 80);

        map_skill("sword", "huashan-sword");
        map_skill("parry", "huashan-sword");
        map_skill("force", "zixia-shengong");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "huntian-zhang");
        map_skill("dodge", "feiyan-huixiang");
        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "huntian-zhang");

        create_family("��ɽ��", 21, "����");

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("gold", 5);

}
void init()
{
        add_action("do_check", "check");
        add_action("do_check", "chazhang");
        add_action("do_convert", "convert");
        add_action("do_convert", "duihuan");
        add_action("do_deposit", "deposit");
        add_action("do_deposit", "cun");
        add_action("do_withdraw", "withdraw");
        add_action("do_withdraw", "qu");
        delete_temp("busy");
}
