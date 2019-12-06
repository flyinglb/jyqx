                 // chen.c

inherit NPC;
#include <ansi.h>
int ask_me();
void destroy(object obj)
{
        if(!obj) return;
        obj->move(VOID_OB);
        destruct(obj);
}

void create()
{
        set_name("���е�", ({ "chen youde", "chen" }));
        set("long", "���е���������ݹݳ���\n");
        set("gender", "����");
        set("age", 45);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("parry", 80);
        set_skill("claw", 80);
        set_skill("hand", 80);
        set_skill("strike", 80);
        set_skill("finger", 80);
        set_skill("cuff", 80);
        set_skill("blade", 80);
        set_skill("stick", 80);
        set_skill("club", 80);
        set_skill("staff", 80);
        set_skill("sword", 80);
        set_skill("throwing", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);
        
        set("inquiry", ([
                "ͭ��" : (: ask_me :),
        ]));

        setup();

}

int ask_me()
{
        object me = this_player();
        me->set_temp("marke/chenyoude_tong_ren", 1);
        write("���е¶���˵����ͭ������һλ����������ͼֽ���ɵģ�10 ���ƽ𣬲����ۣ�\n");
        return 1;
}

int accept_object(object who, object ob)
{
        object obj;
        if ( ob->query("money_id") && ob->value() >= 100000 ) {
                if(!who->query_temp("marke/chenyoude_tong_ren")) {
                        message_vision("���е¶�$N˵����ĳ������������»���������ô��Ǯ��ʲô��\n" , who);
                        return 0;
                }
                who->delete_temp("marks/chenyoude_tong_ren");
                obj = new("/d/npc/obj/tong-box");
                obj->set("buy_master", who->query("id"));
                
                if(!obj->move(who)) obj->move(environment(who));
                
                message_vision("���е¶�$N˵������������ˣ���ҪС��ʹ�ð���\n" , who);
//                command("whisper "+who->query("id")+" ����������ȵô�(open)�������˼ǵ���(shou)������")
                command("whisper "+who->query("id")+" ����������ȵô�(open)��");
                    call_out("destroy",1,ob);
                return 1;
        }
        if (who->query("combat_exp")>= 3500) {
                message_vision("���е�����$N˵������书Ӧ���������������ٳ�����������û�������ˡ�\n", who);
                return 0;
        }
        if (ob->query("money_id") && ob->value() >= 500) {
                who->set_temp("marks/yangzhou_paied",1);
                message_vision("���е¶�$N˵���ã���λ" + RANK_D->query_respect(who) + "��ѧʲô�أ�\n" , who);
                return 1;
        } else
                message_vision("���е���ü��$N˵��Ǯ�Ҳ��ں�������Ҳ����Ҳ̫���˵���ɣ�\n", who);
                return 0;
        }

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("marks/yangzhou_paied")==1) return 0;
        return 1;
}
