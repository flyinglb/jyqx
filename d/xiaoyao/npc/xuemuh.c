//xuemuh.c ѦĽ��
// edward.2000.3

inherit NPC;
inherit F_MASTER;
#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

int ask_me();
int ask_tool();
void do_dest(object obj);

//void attempt_apprentice(object ob);
void create()
{
        set_name(HIC"ѦĽ��"NOR, ({ "xue muhua", "xue" }));
        set("long", 
                HIC"�����Ǻų������е���ҽ����ѦĽ������˵����ͨҽ����������������\n"NOR);
        set("gender", "����");
        set("title","��ң��"MAG"�����Ȱ��ѡ�");
        set("nickname",HIY"������Ѧ��ҽ"NOR);
        set("age", 50);
        set("class", "shaman");
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 27);
        set("con", 25);
        set("dex", 25);
        set("inquiry", ([
                "����" : (:ask_me:),
                "����" : (:ask_tool:),
                "tool" : (:ask_tool:),
        ]) );

        set("max_qi", 1500);
        set("max_jing", 600);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 60);
        set("combat_exp", 150000);
        set("score", 80000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
        set_skill("lingboweibu",90);
        set_skill("beiming-shengong", 90);
        set_skill("zhemei-shou", 90);
        set_skill("literate",100);
        set("chat_chance", 2);
        set("chat_msg", ({
                HIC"ѦĽ��"NOR"˵����""��Ҫ�����ˡ�˭������.......\n",
                HIC"ѦĽ��"NOR"˵����""���������˵ķ������ҿɲ���˵\n",
        }) );


        map_skill("unarmed", "zhemei-shou");
        map_skill("dodge", "lingboweibu");
        map_skill("force", "beiming-shengong");

//      prepare_skill("hand","zhemei-shou");

        create_family("��ң��", 3, "����");
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("say �ðɣ��Ҿ��������ˣ��Ժ�Ҫ��Ϊ��ң�ɳ�������");
        command("recruit " + ob->query("id"));
 }

int ask_me()
{
        object ob;
        ob=this_player();

        if (ob->query("family/family_name") != "��ң��")
                return notify_fail("���У��㲻�����ɵ��ӣ��Ҳ�����Ϊ�����ˡ��㵽��ĵط�ȥ��\n");
        if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
        {
                command("?"+ob->query("id"));     
                command("say ��û�����κ��˰���\n");
                return 1;
        }
        else
        {
                message_vision("ѦĽ��ι$N����һ��ҩ��,Ȼ��˫������$N�ı��ġ�\n", ob);
                remove_call_out("recover");
                call_out("recover",2,ob);
                return 1;
        }
}

int ask_tool()
{
        object who;
        who = this_player();
if(!who->query_temp("job_xiaoyao") || who->query("family/family_name") != "��ң��") {
                write(name()+"����˵������Ҫ���������\n");
                 return 1;
        }
        if( objectp(present("yao chu", who)) ) {
                write(name()+"����˵�����㲻����ҩ���𣿿�ȥ��ҩ�����ҵ������ء�\n");
                return 1;
        }
        message_vision(name()+"��$N˵������������������æ���ˣ��ǾͰ���ȥҩ�Ȳ�ҩ�ɣ�\n", who);
        who->set_temp("job_xiaoyao_tool",1);//�����߱��
        new(__DIR__"obj/yaochu")->move(who);
        tell_object(who, name()+"����һ��ҩ����\n"); 
        return 1;
}

int accept_object(object who, object ob)
{
        if (ob->query("id") == "cao yao" && ob->name() == "��ҩ" && ob->query("job") ) {
                if( ob->query_temp("finish_id") != who->query("id") ) {
                message_vision(name()+"��$Nŭ�������˵Ķ�����Ҳ����˼�ø��ң�\n", who);
                return 0;
                } else {
                message_vision(name()+"��$N˵�����ɵĲ����������ˣ�\n", who);
                ob->delete_temp("finish_id");
                who->add("combat_exp",400+random(20));
                who->add("potential",30+random(10));
                call_out("do_dest",1,ob);
                return 1;
                }
            }
        message_vision(name()+"��$N˵�����ⲻ������Ҫ�ġ�\n", who);
        return 0;
}

void do_dest(object obj)
{
        if(!objectp(obj)) return;
        obj->move(find_object(VOID_OB));//��ȥ����
        destruct(obj);
}

int recover(object ob)
{
        ob->set("eff_qi", (int)ob->query("max_qi"));
        ob->set("eff_jing", (int)ob->query("max_jing"));  
        message_vision("��Լ����һ�Ѳ��ʱ�ݣ�ѦĽ�������ջ�˫�֡���\n",ob);
        command("say ��������Ѿ�ȫ����,����������\n");
        return 1;
}
    
