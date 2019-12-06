// band.c
// Created by Eatdami@MX (10/15/2000)

inherit F_DBASE;
inherit F_SAVE;

void load_banned_sites();
void add_banned_site(string site);
void del_banned_site(string site);
int  is_banned(string site);
void open_netclub(object user);
void load_netclub_ids();
int  is_netclub_id(string id);
void add_netclub_id(string id);

string *Sites = ({});
mapping Netclubs = ([]);

void init_netclub_data()
{
        int i;
        string *index;

        index = keys(Netclubs);
        for( i = sizeof(Netclubs) -1; i >= 0; i-- )
                Netclubs[index[i]] = "";
}

void create()
{
        seteuid(getuid());
        set("name","���羫��");
        set("id","Netclub");
        restore();
        init_netclub_data();
}

string query_save_file()
{
        return DATA_DIR + "daemons/band";
}

int is_banned(string site)
{
        if( member_array(site,Sites) != -1 )
                return 1;
        return 0;
}

int is_netclub_id(string id)
{
        if( member_array(id,keys(Netclubs)) != -1 )
                return 1;
        return 0;
}

int is_netclub(string site)
{
        if( member_array(site,values(Netclubs)) != -1 )
                return 1;
        return 0;
}

int is_allowed_multilogin(string site)
{
        //first check if a netclub address
        //then check if link is more than max_multilogin


        object *usr;
        int i,ip_count,max_multilogin;

        
        max_multilogin = is_netclub(site) ? 30 : 5;

        usr = children(USER_OB);
        for( i = sizeof(usr)-1,ip_count = 0; i >=0; i-- )
                if( site == query_ip_number(usr[i])
                ||  site == usr[i]->query_temp("current_from") )
                        ip_count ++;

        if( ip_count >= max_multilogin )
                return 0;
        return 1;
}

void print_banned_sites()
{
        int i,s;

        if( s = sizeof(Sites) )
                write(HIY"���ڽ�ֹ��վ���У�\n"NOR);
        else {
                write("����û�б���ֹ��վ�㡣\n");
                return;
        }
        for (i = 0; i < s; i++)
                write(HIR+Sites[i] + "\n"NOR);
}

void add_banned_site(string site)
{
        if( is_banned(site) ) {
                write(site + " �ѱ���ֹ��¼��\n");
                return;
        }
        write("��ֹ��"+site+" ��\n");
        Sites += ({site});
        save();
}

void del_banned_site(string site)
{
        if( !is_banned(site) ) {
                write(site + " δ����ֹ��¼��\n");
                return;
        }
        write("�����"+site+"��\n");
        Sites -= ({site});
        save();
}

void add_netclub_id(string id)
{
        object ob;

        if( is_netclub_id(id) ) {
                write(id + " ��������ID��\n");
                return;
        }
        write("��������ID��"+id+" ��\n");
        Netclubs += ([id:""]);
        if( ob = find_player(id) ) {
                Netclubs[id] = query_ip_number(ob);
                CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s)�����ɵ�ַ��%s"
                ,ob->query("name"),id,query_ip_number(ob)));
        }                
        save();
}

void del_netclub_id(string id)
{

        if( !is_netclub_id(id) ) {
                write(id + " ��������ID��\n");
                return;
        }
        write("ɾ������ID��"+id+" ��\n");
        map_delete(Netclubs,id);
        save();
}

void open_netclub(object user)
{
        string id;

        if( !user )
                return;
        id = user->query("id");

        if( is_netclub_id(id) ) {
                Netclubs[id] = query_ip_number(user);
                CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s)�����ɵ�ַ��%s"
                ,user->query("name"),id,query_ip_number(user)));
        }
        save();
}

void close_netclub(object user)
{
        string id,site,*index;
        object *ob;
        int i;

        if( !user )
                return;

        ob = users() - ({ user });
        site = query_ip_number(user);
        for( i = sizeof(ob)-1; i >=0; i-- )
                if( site == query_ip_number(ob[i]) )
                        return;

        id = user->query("id");
        index = keys(Netclubs);
        for( i = sizeof(Netclubs) -1; i >= 0; i-- ) {
                if( Netclubs[index[i]] == site ) {
                        Netclubs[index[i]] = "";
                        CHANNEL_D->do_channel(this_object(),"sys",sprintf("%s(%s)�ر����ɵ�ַ��%s"
                        ,user->query("name"),id,query_ip_number(user)));
                }
        }
        save();
}

void print_netclub()
{
        int i,s;

        if( s = sizeof(Netclubs) )
                write(HIY"���ڴ��ڵ������У�\n"NOR);
        else {
                write("����û�б��Ѿ���������ɡ�\n");
                return;
        }
        for (i = 0; i < s; i++)
                write(HIC"ID: " + keys(Netclubs)[i] + " IP: " + values(Netclubs)[i] + "\n"NOR);
        return;
}
