// �����п�
#include <ansi.h>

inherit NPC;

string *rnd_say = ({
        "�������пգ����������µĴ�Ӣ�ۣ������ý����ѡ�������˾�Ȼ�������ң�",
        "Ϊʲ��˾��������С���ﻹû�����ֺ��Ǹ�С���˵���һ�����ˣ�",
        "��˭���Ը���һЩǮ�������һǧ�����ӻ��ҵ�ʱ�����ٻ�����ɣ�",
        "���뿴������ƨ�����ƽɳ����ʽ��",
        "���������ͺ¿�����ﻹ���Ƿ��ɣ������������",
        "�Ǹ���ľɭ��ţ����Ϊʲô���������ǣ�",
        "�������С�쵰�����",
        "���ŵ���ü��˵��Ư����",
        "���������ʲô��",
        "��Ѵ󱦺Ͷ�������һ�����⣡",
        "���Ͼ���α���ӣ�����",
        "���Ǻ�βè��",
        "��..",
});

void greeting(object ob);
void stealing(object ob);
varargs void drool(string msg, string who);

void create()
{
        set_name("�����п�", ({ "skywalker" }) );
        set("title", "��ͨ����");
        set("gender", "����");
        set("age", 14);
        set("attitude", "friendly");
        set("combat_exp", 10000000);
        set("env/wimpy", 100);
        set("chat_chance", 200);
        set_skill("stealing", 300);
	set("str", 85);
	set("con", 85);
	set("int", 85);
	set("dex", 85);
	set("kar", 100);
	set("max_qi", 5000);
	set("max_jing", 2000);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("shen_type", 0);
	set("thief", 0);
        set("chat_msg", ({
                "�������пգ����������µĴ�Ӣ�ۣ������ý����ѡ�������˾�Ȼ�������ң�\n",
                "���ŵ���ü��˵��Ư����\n",
                "���������ʲô��\n",
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
        }) );
        setup();
	carry_object("/clone/misc/cloth")->wear();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
}

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "��", "");
        msg = replace_string(msg, "Ү", "");
        msg = replace_string(msg, "��", "");

        if( msg!="" ) {
                add("memory/" + who, ({ msg }));
                return 1;
        } else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
        string who;

        if( !userp(ob) || (channel != "chat") ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
        string who;

//        if( !userp(ob) ) return;
        who = ob->query("name");

        // Don't process our own speech
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) && random(10) > 4 )
                drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "poke":
                command("poke skywalker");
                break;
        case "sorry":
        case "thank":
        case "admire":
        case "thumb":
        case "u&me":
        case "slapsb":
        case "rich":
        case "handsome":
                if( random(10)<5 )
                      command("hehe");
                else
                      command("nali " + ob->query("id"));
                break;
        case "u&me2":
        case "aunt":
        case "visit":
        case "sister":
        case "brother":
        case "bow":
                if( random(10)<5 )
                      command("hehe");
                else
                      command("shy");
                break;
        case "gongxi":
                command("tongxi " + ob->query("id"));
                break;
        case "sigh":
        case "poor":
                if( random(10)<5 )
                      command("say Ϊʲ��̾����");
                else
                      command("laugh " + ob->query("id"));
                break;
        case "kick":
        case "kick1":
        case "kick2":
        case "foot":
        case "pai":
                if( random(10)<5 )
                      command("say Ϊʲ�����ң���ʹҮ��");
                else
                      command(verb + " " + ob->query("id"));
                break;
        case "wake":
        case "pig":
        case "zhu":
                if( random(10)<5 )
                      command("say ��������أ�");
                else
                      command(verb + " " + ob->query("id"));
                break;
        case "shout":
        case "grin":
        case "xixi":
        case "hehe":
        case "heihei":
        case "laugh":
        case "sneer":
        case "heng":
        case "story":
        case "smirk":
        case "sing":
        case "sing2":
        case "sing3":
        case "yehua":
                if( random(10)<5 )
                      command("say ��˯�ž͸��㳳���ˣ�");
                else
                      command("seal");
                break;
        case "slap":
        case "club":
        case "hammer":
        case "hammer1":
        case "hammer2":
        case "maimai":
                if( random(10)<5 )
                      command("say Ϊʲ����ң���ʹҮ��");
                else
                      command(verb + " " + ob->query("id"));
                break;
        default:
                if( random(10)<5 )
                      command(verb + " " + ob->query("id"));
                else
                      command("waggle " + ob->query("id"));
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;
        string mrh;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }
        mrh="";

        if( strsrch(msg, "�쵰") >=0 ) mrh="С�쵰";
        else if( strsrch(msg, "�뵰") >=0 ) mrh="��뵰";
        else if( strsrch(msg, "��") >=0 ) mrh="С����";
        else if( strsrch(msg, "����") >=0 ) mrh="������";
        else if( strsrch(msg, "����") >=0 ) mrh="�󻵵�";
        else if( strsrch(msg, "����") >=0 ) mrh="С����";
        else if( strsrch(msg, "¿") >=0 ) mrh="��¿��";
        else if( strsrch(msg, "����") >=0 ) mrh="С����";
        else if( strsrch(msg, "����") >=0 ) mrh="������";
        else if( strsrch(msg, "������") >=0 ) mrh="С������";
        else if( strsrch(msg, "��å") >=0 ) mrh="����å";
        else if( strsrch(msg, "����") >=0 ) mrh="������";
        else if( strsrch(msg, "����") >=0 ) mrh="С����";
        else if( strsrch(msg, "��Ů") >=0 ) mrh="С��Ů";
        else if( strsrch(msg, "�깫") >=0 ) mrh="С�깫";
        if (mrh!="") {
              switch(random(20)) {
              case 0: command("say " + who + "����˵�Լ���"); break;
              case 1: command("say " + who + "��˵�Լ���" + mrh + "��"); break;
              case 2: command("kick2 " + who); break;
              case 3: command("slap " + who); break;
              case 4: command("hammer " + who); break;
              case 5: command("taunt " + who); break;
              case 6: command("rascal " + who); break;
              case 7: command("grin " + who); break;
              case 8: command("slogan " + who); break;
              case 9: command("kick1 " + who); break;
              case 10: command("foot " + who); break;
              case 11: command("maimai " + who); break;
              case 12: command("pai " + who); break;
              default: command("say ���ǿ�ʼ�����й�" + who + "��" + mrh + "�Ļ������");
              }
        }
        else if( (strsrch(msg, "Ϊʲ��") >= 0) ) {
                if( sscanf(msg, "%*sΪʲ��%s", msg)==2 ) msg = "Ϊʲ��" + msg;
                switch(random(20)) {
                case 0: command("say " + who + "��������������"); break;
                case 1: command("say ���" + msg + " ... "); break;
                case 2: command("say �� ... "); drool(); break;
                case 3: command("say ��������� ...."); break;
                case 4: command("say " + who + "��֪���������Ĵ𰸶���������Ҫô��"); break;
                case 5: command("say " + msg + "��"); break;
                case 6: command("say " + who + "���ܲ���˵���һ�㣿"); break;
                case 7: command("say " + who + "���Ҳ������ʵ�����"); break;
                case 8: command("say " + who + "��С���˵������ʣ�"); break;
                default: command("? " + who ); break;
                }
        }
        else if( (strsrch(msg, "��") >= 0)
        ||      (strsrch(msg, "��") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "��", "��");
                switch(random(20)) {
                case 0: command("say " + who + "������˵" + msg + "��");break;
                case 1: command("say ��ȷ��" + msg + "��");     break;
                case 2: command("say " + msg + "������ʲ���ϵ��");     break;
                case 3: command("say �� ... " + who + "˵�ú�"); break;
                case 4: command("say " + who + "��Ϊʲ���" + msg + "��������Ȥ��"); break;
                case 5: command("say Ϊʲ������Ϊ" + msg + "��"); break;
                case 6: command("say ���������"); drool(); break;
                case 7: command("say �Ź�"); break;
                case 8: command("say ��һ���ɣ�"); break;
                default: command("say ��������� ...."); break;
                }
        }
        else if( (strsrch(msg, "��") >= 0)) {
                if( sscanf(msg, "%*s��%s", msg) == 2 ) msg = "��" + msg;
                msg = replace_string(msg, "��", "��");
                msg = replace_string(msg, "?", "");
                switch(random(20)) {
                case 0: command("say ����˵" + msg + "��"); break;
                case 1: command("say ��ģ�" + msg + "��");     break;
                case 2: command("say ���" + msg + "�����ܰ���ʲ��æ��");break
;
                case 3: command("hmm"); break;
                case 4: command("say ����Ϊ" + msg + "��"); break;
                case 5: command("say ����ͬ��"); break;
                case 6: command("say ��˵�ġ�" + msg + "���Ҳ��ܹ�ͬ"); break;
                default: command("say �йء�" + msg + "���Ļ��⵽��Ϊֹ����");break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("say Ϊʲ��˵" + msg + "?"); break;
                        case 1: command("say ��" + msg + "����ʲ����˼��"); break;
                        case 2: command("say " + msg + "��"); break;
                        case 3: command("grin"); break;
                        case 4: command("smile"); break;
                        case 5: command("?"); break;
                        case 6: command("say ...."); break;
                        case 7: command("hmm"); break;
                        case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
                        case 9: command("say ������֪��" + msg + "?"); break;
                        case 10: command("say �ո�" + who + "����˵�ˣ�" + msg);
                        case 11: command("say �ҵ�Ȼ֪����" + msg); break;
                        case 12: command("say Ȼ���أ�"); break;
                        case 13: command("say �����"); break;
                        case 14: command("say �Ҳ�������Ϊ��"); break;
                        default: command("say �ҿɲ�֪����"); break;
                }
        }
}

void reset()
{
        delete("memory");
}

int accept_object()
{
        return 1;
}
void init()
{
    object ob;

    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) {
//         remove_call_out("stealing");
//         call_out("stealing", 5, ob);
         stealing(ob);
         remove_call_out("greeting");
         call_out("greeting", 1, ob);
    }
    add_action("do_dajia","hit");
    add_action("do_kill","kill");
    add_action("do_dajia","fight");
}

void greeting(object ob)
{
    if ( !ob || environment(ob) != environment() )
          return;
    say( "�����п����ڿ���һλ���ѣ���æ��������������ֵ��ҺȾƣ�\n");
    if (!wizardp(ob))
    {
          message_vision("�����пճ���$N����������һ�������ó���$Nֱð��\n",ob,ob);
          ob->apply_condition("drunk", 20);
    }
}

void stealing(object ob)
{
      if( !ob || environment(ob) != environment() || ob->query_int() > 30 )
            return;

      switch( random(3) ) {
            case 0:
                  command("hehe " + ob->query("id"));
                  command("steal coin from " + ob->query("id"));
                  break;
            case 1:
                  command("grin " + ob->query("id"));
                  command("steal silver from " + ob->query("id"));                  
                  break;
            case 2:
                  command("hi " + ob->query("id"));
                  command("steal gold from " + ob->query("id"));                  
                  break;
      }
}

int do_dajia()
{
    object ob;

    ob = this_player();
    message_vision("�����п�������ȭ��$Nһ�ٳ���\n",ob);
    message_vision("$N���ڵ��ϣ���У������п�үү����Ӣ���������������п�һ��\n",ob);
    message_vision("����ʱ¶��Ц�ݣ���$N���۹⣬�����Ǹ����ˣ����ֲ����ˣ�\n",ob);
    ob -> set("qi",10);
    return 1;
}

int do_kill()
{
    object ob;
    ob = this_player();
    message_vision("�����п�������ȭ��$N�����������ץס\n",ob);
    message_vision("$N˫�ţ��ٵ�һ���ͺȣ�ֻ����һ���Һ���������Ѫ����\n",ob);
    message_vision("$N����������˺����Ƭ������ʵ����̫���ˣ����˶��Ȼ����ˣ�\n",ob);
    ob->die();
    return 1;
}

