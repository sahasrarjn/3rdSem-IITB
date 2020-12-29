--
-- PostgreSQL database dump
--

-- Dumped from database version 13.0
-- Dumped by pg_dump version 13.0

-- Started on 2020-10-24 12:48:46 IST

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 207 (class 1259 OID 16417)
-- Name: auth_group; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.auth_group (
    id integer NOT NULL,
    name character varying(150) NOT NULL
);


ALTER TABLE public.auth_group OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 206 (class 1259 OID 16415)
-- Name: auth_group_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.auth_group_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.auth_group_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3386 (class 0 OID 0)
-- Dependencies: 206
-- Name: auth_group_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER SEQUENCE public.auth_group_id_seq OWNED BY public.auth_group.id;


--
-- TOC entry 209 (class 1259 OID 16427)
-- Name: auth_group_permissions; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.auth_group_permissions (
    id integer NOT NULL,
    group_id integer NOT NULL,
    permission_id integer NOT NULL
);


ALTER TABLE public.auth_group_permissions OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 208 (class 1259 OID 16425)
-- Name: auth_group_permissions_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.auth_group_permissions_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.auth_group_permissions_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3387 (class 0 OID 0)
-- Dependencies: 208
-- Name: auth_group_permissions_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER SEQUENCE public.auth_group_permissions_id_seq OWNED BY public.auth_group_permissions.id;


--
-- TOC entry 205 (class 1259 OID 16409)
-- Name: auth_permission; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.auth_permission (
    id integer NOT NULL,
    name character varying(255) NOT NULL,
    content_type_id integer NOT NULL,
    codename character varying(100) NOT NULL
);


ALTER TABLE public.auth_permission OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 204 (class 1259 OID 16407)
-- Name: auth_permission_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.auth_permission_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.auth_permission_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3388 (class 0 OID 0)
-- Dependencies: 204
-- Name: auth_permission_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER SEQUENCE public.auth_permission_id_seq OWNED BY public.auth_permission.id;


--
-- TOC entry 211 (class 1259 OID 16435)
-- Name: auth_user; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.auth_user (
    id integer NOT NULL,
    password character varying(128) NOT NULL,
    last_login timestamp with time zone,
    is_superuser boolean NOT NULL,
    username character varying(150) NOT NULL,
    first_name character varying(150) NOT NULL,
    last_name character varying(150) NOT NULL,
    email character varying(254) NOT NULL,
    is_staff boolean NOT NULL,
    is_active boolean NOT NULL,
    date_joined timestamp with time zone NOT NULL
);


ALTER TABLE public.auth_user OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 213 (class 1259 OID 16445)
-- Name: auth_user_groups; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.auth_user_groups (
    id integer NOT NULL,
    user_id integer NOT NULL,
    group_id integer NOT NULL
);


ALTER TABLE public.auth_user_groups OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 212 (class 1259 OID 16443)
-- Name: auth_user_groups_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.auth_user_groups_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.auth_user_groups_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3389 (class 0 OID 0)
-- Dependencies: 212
-- Name: auth_user_groups_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER SEQUENCE public.auth_user_groups_id_seq OWNED BY public.auth_user_groups.id;


--
-- TOC entry 210 (class 1259 OID 16433)
-- Name: auth_user_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.auth_user_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.auth_user_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3390 (class 0 OID 0)
-- Dependencies: 210
-- Name: auth_user_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER SEQUENCE public.auth_user_id_seq OWNED BY public.auth_user.id;


--
-- TOC entry 215 (class 1259 OID 16453)
-- Name: auth_user_user_permissions; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.auth_user_user_permissions (
    id integer NOT NULL,
    user_id integer NOT NULL,
    permission_id integer NOT NULL
);


ALTER TABLE public.auth_user_user_permissions OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 214 (class 1259 OID 16451)
-- Name: auth_user_user_permissions_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.auth_user_user_permissions_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.auth_user_user_permissions_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3391 (class 0 OID 0)
-- Dependencies: 214
-- Name: auth_user_user_permissions_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER SEQUENCE public.auth_user_user_permissions_id_seq OWNED BY public.auth_user_user_permissions.id;


--
-- TOC entry 217 (class 1259 OID 16513)
-- Name: django_admin_log; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.django_admin_log (
    id integer NOT NULL,
    action_time timestamp with time zone NOT NULL,
    object_id text,
    object_repr character varying(200) NOT NULL,
    action_flag smallint NOT NULL,
    change_message text NOT NULL,
    content_type_id integer,
    user_id integer NOT NULL,
    CONSTRAINT django_admin_log_action_flag_check CHECK ((action_flag >= 0))
);


ALTER TABLE public.django_admin_log OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 216 (class 1259 OID 16511)
-- Name: django_admin_log_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.django_admin_log_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.django_admin_log_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3392 (class 0 OID 0)
-- Dependencies: 216
-- Name: django_admin_log_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER SEQUENCE public.django_admin_log_id_seq OWNED BY public.django_admin_log.id;


--
-- TOC entry 203 (class 1259 OID 16399)
-- Name: django_content_type; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.django_content_type (
    id integer NOT NULL,
    app_label character varying(100) NOT NULL,
    model character varying(100) NOT NULL
);


ALTER TABLE public.django_content_type OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 202 (class 1259 OID 16397)
-- Name: django_content_type_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.django_content_type_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.django_content_type_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3393 (class 0 OID 0)
-- Dependencies: 202
-- Name: django_content_type_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER SEQUENCE public.django_content_type_id_seq OWNED BY public.django_content_type.id;


--
-- TOC entry 201 (class 1259 OID 16388)
-- Name: django_migrations; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.django_migrations (
    id integer NOT NULL,
    app character varying(255) NOT NULL,
    name character varying(255) NOT NULL,
    applied timestamp with time zone NOT NULL
);


ALTER TABLE public.django_migrations OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 200 (class 1259 OID 16386)
-- Name: django_migrations_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.django_migrations_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.django_migrations_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3394 (class 0 OID 0)
-- Dependencies: 200
-- Name: django_migrations_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER SEQUENCE public.django_migrations_id_seq OWNED BY public.django_migrations.id;


--
-- TOC entry 218 (class 1259 OID 16544)
-- Name: django_session; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.django_session (
    session_key character varying(40) NOT NULL,
    session_data text NOT NULL,
    expire_date timestamp with time zone NOT NULL
);


ALTER TABLE public.django_session OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 220 (class 1259 OID 16578)
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE SEQUENCE public.users_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    MAXVALUE 100000
    CACHE 1;


ALTER TABLE public.users_id_seq OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 219 (class 1259 OID 16565)
-- Name: users; Type: TABLE; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE TABLE public.users (
    id integer DEFAULT nextval('public.users_id_seq'::regclass) NOT NULL,
    user_fk integer,
    image text
);


ALTER TABLE public.users OWNER TO xvkgdchrbgymzd;

--
-- TOC entry 3183 (class 2604 OID 16420)
-- Name: auth_group id; Type: DEFAULT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_group ALTER COLUMN id SET DEFAULT nextval('public.auth_group_id_seq'::regclass);


--
-- TOC entry 3184 (class 2604 OID 16430)
-- Name: auth_group_permissions id; Type: DEFAULT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_group_permissions ALTER COLUMN id SET DEFAULT nextval('public.auth_group_permissions_id_seq'::regclass);


--
-- TOC entry 3182 (class 2604 OID 16412)
-- Name: auth_permission id; Type: DEFAULT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_permission ALTER COLUMN id SET DEFAULT nextval('public.auth_permission_id_seq'::regclass);


--
-- TOC entry 3185 (class 2604 OID 16438)
-- Name: auth_user id; Type: DEFAULT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user ALTER COLUMN id SET DEFAULT nextval('public.auth_user_id_seq'::regclass);


--
-- TOC entry 3186 (class 2604 OID 16448)
-- Name: auth_user_groups id; Type: DEFAULT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_groups ALTER COLUMN id SET DEFAULT nextval('public.auth_user_groups_id_seq'::regclass);


--
-- TOC entry 3187 (class 2604 OID 16456)
-- Name: auth_user_user_permissions id; Type: DEFAULT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_user_permissions ALTER COLUMN id SET DEFAULT nextval('public.auth_user_user_permissions_id_seq'::regclass);


--
-- TOC entry 3188 (class 2604 OID 16516)
-- Name: django_admin_log id; Type: DEFAULT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_admin_log ALTER COLUMN id SET DEFAULT nextval('public.django_admin_log_id_seq'::regclass);


--
-- TOC entry 3181 (class 2604 OID 16402)
-- Name: django_content_type id; Type: DEFAULT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_content_type ALTER COLUMN id SET DEFAULT nextval('public.django_content_type_id_seq'::regclass);


--
-- TOC entry 3180 (class 2604 OID 16391)
-- Name: django_migrations id; Type: DEFAULT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_migrations ALTER COLUMN id SET DEFAULT nextval('public.django_migrations_id_seq'::regclass);


--
-- TOC entry 3204 (class 2606 OID 16542)
-- Name: auth_group auth_group_name_key; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_group
    ADD CONSTRAINT auth_group_name_key UNIQUE (name);


--
-- TOC entry 3209 (class 2606 OID 16469)
-- Name: auth_group_permissions auth_group_permissions_group_id_permission_id_0cd325b0_uniq; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_group_permissions
    ADD CONSTRAINT auth_group_permissions_group_id_permission_id_0cd325b0_uniq UNIQUE (group_id, permission_id);


--
-- TOC entry 3212 (class 2606 OID 16432)
-- Name: auth_group_permissions auth_group_permissions_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_group_permissions
    ADD CONSTRAINT auth_group_permissions_pkey PRIMARY KEY (id);


--
-- TOC entry 3206 (class 2606 OID 16422)
-- Name: auth_group auth_group_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_group
    ADD CONSTRAINT auth_group_pkey PRIMARY KEY (id);


--
-- TOC entry 3199 (class 2606 OID 16460)
-- Name: auth_permission auth_permission_content_type_id_codename_01ab375a_uniq; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_permission
    ADD CONSTRAINT auth_permission_content_type_id_codename_01ab375a_uniq UNIQUE (content_type_id, codename);


--
-- TOC entry 3201 (class 2606 OID 16414)
-- Name: auth_permission auth_permission_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_permission
    ADD CONSTRAINT auth_permission_pkey PRIMARY KEY (id);


--
-- TOC entry 3220 (class 2606 OID 16450)
-- Name: auth_user_groups auth_user_groups_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_groups
    ADD CONSTRAINT auth_user_groups_pkey PRIMARY KEY (id);


--
-- TOC entry 3223 (class 2606 OID 16484)
-- Name: auth_user_groups auth_user_groups_user_id_group_id_94350c0c_uniq; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_groups
    ADD CONSTRAINT auth_user_groups_user_id_group_id_94350c0c_uniq UNIQUE (user_id, group_id);


--
-- TOC entry 3214 (class 2606 OID 16440)
-- Name: auth_user auth_user_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user
    ADD CONSTRAINT auth_user_pkey PRIMARY KEY (id);


--
-- TOC entry 3226 (class 2606 OID 16458)
-- Name: auth_user_user_permissions auth_user_user_permissions_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_user_permissions
    ADD CONSTRAINT auth_user_user_permissions_pkey PRIMARY KEY (id);


--
-- TOC entry 3229 (class 2606 OID 16498)
-- Name: auth_user_user_permissions auth_user_user_permissions_user_id_permission_id_14a6b632_uniq; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_user_permissions
    ADD CONSTRAINT auth_user_user_permissions_user_id_permission_id_14a6b632_uniq UNIQUE (user_id, permission_id);


--
-- TOC entry 3217 (class 2606 OID 16536)
-- Name: auth_user auth_user_username_key; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user
    ADD CONSTRAINT auth_user_username_key UNIQUE (username);


--
-- TOC entry 3232 (class 2606 OID 16522)
-- Name: django_admin_log django_admin_log_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_admin_log
    ADD CONSTRAINT django_admin_log_pkey PRIMARY KEY (id);


--
-- TOC entry 3194 (class 2606 OID 16406)
-- Name: django_content_type django_content_type_app_label_model_76bd3d3b_uniq; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_content_type
    ADD CONSTRAINT django_content_type_app_label_model_76bd3d3b_uniq UNIQUE (app_label, model);


--
-- TOC entry 3196 (class 2606 OID 16404)
-- Name: django_content_type django_content_type_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_content_type
    ADD CONSTRAINT django_content_type_pkey PRIMARY KEY (id);


--
-- TOC entry 3192 (class 2606 OID 16396)
-- Name: django_migrations django_migrations_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_migrations
    ADD CONSTRAINT django_migrations_pkey PRIMARY KEY (id);


--
-- TOC entry 3236 (class 2606 OID 16551)
-- Name: django_session django_session_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_session
    ADD CONSTRAINT django_session_pkey PRIMARY KEY (session_key);


--
-- TOC entry 3240 (class 2606 OID 16569)
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- TOC entry 3202 (class 1259 OID 16543)
-- Name: auth_group_name_a6ea08ec_like; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX auth_group_name_a6ea08ec_like ON public.auth_group USING btree (name varchar_pattern_ops);


--
-- TOC entry 3207 (class 1259 OID 16480)
-- Name: auth_group_permissions_group_id_b120cbf9; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX auth_group_permissions_group_id_b120cbf9 ON public.auth_group_permissions USING btree (group_id);


--
-- TOC entry 3210 (class 1259 OID 16481)
-- Name: auth_group_permissions_permission_id_84c5c92e; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX auth_group_permissions_permission_id_84c5c92e ON public.auth_group_permissions USING btree (permission_id);


--
-- TOC entry 3197 (class 1259 OID 16466)
-- Name: auth_permission_content_type_id_2f476e4b; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX auth_permission_content_type_id_2f476e4b ON public.auth_permission USING btree (content_type_id);


--
-- TOC entry 3218 (class 1259 OID 16496)
-- Name: auth_user_groups_group_id_97559544; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX auth_user_groups_group_id_97559544 ON public.auth_user_groups USING btree (group_id);


--
-- TOC entry 3221 (class 1259 OID 16495)
-- Name: auth_user_groups_user_id_6a12ed8b; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX auth_user_groups_user_id_6a12ed8b ON public.auth_user_groups USING btree (user_id);


--
-- TOC entry 3224 (class 1259 OID 16510)
-- Name: auth_user_user_permissions_permission_id_1fbb5f2c; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX auth_user_user_permissions_permission_id_1fbb5f2c ON public.auth_user_user_permissions USING btree (permission_id);


--
-- TOC entry 3227 (class 1259 OID 16509)
-- Name: auth_user_user_permissions_user_id_a95ead1b; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX auth_user_user_permissions_user_id_a95ead1b ON public.auth_user_user_permissions USING btree (user_id);


--
-- TOC entry 3215 (class 1259 OID 16537)
-- Name: auth_user_username_6821ab7c_like; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX auth_user_username_6821ab7c_like ON public.auth_user USING btree (username varchar_pattern_ops);


--
-- TOC entry 3230 (class 1259 OID 16533)
-- Name: django_admin_log_content_type_id_c4bce8eb; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX django_admin_log_content_type_id_c4bce8eb ON public.django_admin_log USING btree (content_type_id);


--
-- TOC entry 3233 (class 1259 OID 16534)
-- Name: django_admin_log_user_id_c564eba6; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX django_admin_log_user_id_c564eba6 ON public.django_admin_log USING btree (user_id);


--
-- TOC entry 3234 (class 1259 OID 16553)
-- Name: django_session_expire_date_a5c62663; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX django_session_expire_date_a5c62663 ON public.django_session USING btree (expire_date);


--
-- TOC entry 3237 (class 1259 OID 16552)
-- Name: django_session_session_key_c0390e0f_like; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX django_session_session_key_c0390e0f_like ON public.django_session USING btree (session_key varchar_pattern_ops);


--
-- TOC entry 3238 (class 1259 OID 16577)
-- Name: pk_index; Type: INDEX; Schema: public; Owner: poxvkgdchrbgymzds
--

CREATE INDEX pk_index ON public.users USING btree (id);


--
-- TOC entry 3243 (class 2606 OID 16475)
-- Name: auth_group_permissions auth_group_permissio_permission_id_84c5c92e_fk_auth_perm; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_group_permissions
    ADD CONSTRAINT auth_group_permissio_permission_id_84c5c92e_fk_auth_perm FOREIGN KEY (permission_id) REFERENCES public.auth_permission(id) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 3242 (class 2606 OID 16470)
-- Name: auth_group_permissions auth_group_permissions_group_id_b120cbf9_fk_auth_group_id; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_group_permissions
    ADD CONSTRAINT auth_group_permissions_group_id_b120cbf9_fk_auth_group_id FOREIGN KEY (group_id) REFERENCES public.auth_group(id) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 3241 (class 2606 OID 16461)
-- Name: auth_permission auth_permission_content_type_id_2f476e4b_fk_django_co; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_permission
    ADD CONSTRAINT auth_permission_content_type_id_2f476e4b_fk_django_co FOREIGN KEY (content_type_id) REFERENCES public.django_content_type(id) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 3245 (class 2606 OID 16490)
-- Name: auth_user_groups auth_user_groups_group_id_97559544_fk_auth_group_id; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_groups
    ADD CONSTRAINT auth_user_groups_group_id_97559544_fk_auth_group_id FOREIGN KEY (group_id) REFERENCES public.auth_group(id) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 3244 (class 2606 OID 16485)
-- Name: auth_user_groups auth_user_groups_user_id_6a12ed8b_fk_auth_user_id; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_groups
    ADD CONSTRAINT auth_user_groups_user_id_6a12ed8b_fk_auth_user_id FOREIGN KEY (user_id) REFERENCES public.auth_user(id) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 3247 (class 2606 OID 16504)
-- Name: auth_user_user_permissions auth_user_user_permi_permission_id_1fbb5f2c_fk_auth_perm; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_user_permissions
    ADD CONSTRAINT auth_user_user_permi_permission_id_1fbb5f2c_fk_auth_perm FOREIGN KEY (permission_id) REFERENCES public.auth_permission(id) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 3246 (class 2606 OID 16499)
-- Name: auth_user_user_permissions auth_user_user_permissions_user_id_a95ead1b_fk_auth_user_id; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.auth_user_user_permissions
    ADD CONSTRAINT auth_user_user_permissions_user_id_a95ead1b_fk_auth_user_id FOREIGN KEY (user_id) REFERENCES public.auth_user(id) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 3248 (class 2606 OID 16523)
-- Name: django_admin_log django_admin_log_content_type_id_c4bce8eb_fk_django_co; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_admin_log
    ADD CONSTRAINT django_admin_log_content_type_id_c4bce8eb_fk_django_co FOREIGN KEY (content_type_id) REFERENCES public.django_content_type(id) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 3249 (class 2606 OID 16528)
-- Name: django_admin_log django_admin_log_user_id_c564eba6_fk_auth_user_id; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.django_admin_log
    ADD CONSTRAINT django_admin_log_user_id_c564eba6_fk_auth_user_id FOREIGN KEY (user_id) REFERENCES public.auth_user(id) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 3250 (class 2606 OID 16570)
-- Name: users django_user_id; Type: FK CONSTRAINT; Schema: public; Owner: poxvkgdchrbgymzds
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT django_user_id FOREIGN KEY (user_fk) REFERENCES public.auth_user(id);


-- Completed on 2020-10-24 12:48:46 IST

--
-- PostgreSQL database dump complete
--

