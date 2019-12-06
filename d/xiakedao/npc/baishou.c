// baishou.c ������
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("������", ({ "bai zizai", "bai" }));
        set("nickname", "ѩɽ����������");
        set("title", "�����޵�");
        set("long",
                "������ѩɽ���ɵ������ˣ�ϰ����ԣ�����Ϊ�����书��һ��\n"
                "����Լ��ʮ���꣬�����ܸɣ�������������һ�\n");
        set("gender", "����");
        set("age", 55);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2000);
        set("qi", 2000);
        set("jing", 2000);
        set("max_jing", 2000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 125000);
        set("score", 60000);

        set_skill("force", 100);
        set_skill("hand", 170);
        set_skill("dodge", 100);
        set_skill("staff", 170);
        set_skill("unarmed", 100);
        set_skill("hamagong", 200);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("chanchu-bufa", 150);
        set_skill("shexing-diaoshou", 100);
        set_skill("literate", 80);
        set_skill("lingshe-zhangfa", 150);

        map_skill("force", "hamagong");
        map_skill("dodge", "chanchu-bufa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("hand", "shexing-diaoshou");
        map_skill("staff", "lingshe-zhangfa");


        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        carry_object("/d/wudang/obj/whiterobe")->wear();
        add_money("gold",2);
}
void init()
{
        object ob;
        ob = this_player();
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
}


void greeting(object ob)
{
        int i ;
        object me;
        object* obj;
        object obn;
        me = this_object();
        if (interactive(ob)
                && !environment(ob)->query("no_fight"))
        {
                if (ob->query("shen")>0)
                {
                        command("say �ұ�����ѧ�䣬��Ϊ����?");
                        command("say �������壬���������Ȼ�Ǳ��֣���ȴ��ʹ֮С�ߡ�");
                        command("say Ϊ��Ϊ����֮���ߣ���˸��֣��պ��������£���Ϊ�������Ĵ�����");

                        obj = all_inventory(environment(me));
                        for(i=0; i<sizeof(obj); i++)
                        {
                                if(obj[i]==me)
                                        continue;
                                if (random((int)ob->query("kar"))>28)
                                {
command("say ���ܵ��ˣ���Ϊ������Ե��������������������ȥ�ɡ�\n");
                                        obn = new("/d/xiakedao/obj/shane-bu");
                                        obn->move(ob);
command("say �����͵����������ѧ�书�ɣ���������һ��֮����\n");
                                        ob->move("/d/xiakedao/neiting");
tell_object(ob,HIR"��ֻ����ǰһ�ڣ�ʲôҲ��֪���ˣ�����ȴ���صĳ�����һ�������ڡ�\n"NOR);
                                }
command("say ���ܵ��ˣ���Ϊ��Ե���ں���һ�ѽ�������Ե������ȥ�ɡ�\n");
                        }
                }
                else
                {
                        command("say ������Ӧ������·����ȥ�ɡ�");
                }
        }
}
