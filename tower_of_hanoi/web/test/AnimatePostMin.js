function Q() {
    function e(a, b, e, g, k, h) { this.x = a; this.y = b; this.a = e; this.c = g; this.L = k || 0; this.M = h || 0 } var g, k, a = 1, u, b; this.B = function (a) { b ? a() : (u = new Image, u.onload = function () { b = !0; a() }, u.src = "Images/WoodFine0003_S.jpg") }; e.prototype = {
        h: function () { return this.x + this.a / 2 }, i: function (a) {
            a = void 0 == a ? !1 : a; g.translate(this.x + this.L, this.y + this.M); a && (g.strokeStyle = "#00FF00", g.lineWidth = 3); g.beginPath(); g.rect(-this.L, -this.M, this.a, this.c); g.closePath(); g.fill(); g.stroke(); a && (g.strokeStyle = "black", g.lineWidth =
            1); g.translate(-(this.x + this.L), -(this.y + this.M))
        }
    }; this.w = function () { }; this.w.prototype = { g: function () { this.u = 150 * Math.random(); this.v = 150 * Math.random() }, render: function (b) { (new e(b.x * a, b.y * a, b.a * a, b.c * a, this.u, this.v)).i() } }; this.C = function () { }; this.C.prototype = { g: function () { this.u = 150 * Math.random(); this.v = 150 * Math.random() }, render: function (b) { (new e(b.x * a, b.y * a, b.a * a, b.c * a, this.u, this.v)).i() } }; this.A = function () { }; this.A.prototype = {
        g: function () { this.u = 150 * Math.random(); this.v = 150 * Math.random() },
        render: function (b) { (new e(b.x * a, b.y * a, b.a * a, b.c * a, this.u, this.v)).i(b.selected) }
    }; var r; this.J = function (a) { k = a; g = k.getContext("2d"); g.strokeStyle = "black"; r = g.createPattern(u, "repeat"); g.fillStyle = r; this.sa(k.width / 100 * 1) }; this.P = function (a, b) { g.clearRect(0, 0, a, b) }; this.show = function () { }; this.sa = function (b) { a = b }
}
DiscGeometry = function (e, g, k, a, u, b) {
    THREE.Geometry.call(this); this.type = "DiscGeometry"; e = void 0 !== e ? e : 10; g = void 0 !== g ? g : 20; this.height = k = void 0 !== k ? k : 100; this.o = a || 8; u = u || 1; this.s = b; var r = k / 2, m = [], q = [], t = [], n = [], p = new THREE.Vector2(0, 0), h, v; for (b = 0; b <= u; b++) {
        var d = [], w = [], c = [], x = [], z = b / u, y = g; for (a = 0; a <= this.o; a++) {
            var f = a / this.o; h = new THREE.Vector3; h.x = y * Math.sin(f * Math.PI * 2); h.y = -z * k + r; h.z = y * Math.cos(f * Math.PI * 2); this.vertices.push(h); d.push(this.vertices.length - 1); h = Math.sin(f * Math.PI * 2 + this.s);
            v = Math.cos(f * Math.PI * 2 + this.s); w.push(new THREE.Vector2(h / 2 + .5, v / 2 + .5)); var l = new THREE.Vector3; l.x = e * Math.sin(f * Math.PI * 2); l.y = -z * k + r; l.z = e * Math.cos(f * Math.PI * 2); this.vertices.push(l); c.push(this.vertices.length - 1); x.push(new THREE.Vector2(h * e / y / 2 + .5, v * e / y / 2 + .5))
        } m.push(d); q.push(w); t.push(c); n.push(x)
    } for (a = 0; a < this.o; a++) {
        y = this.vertices[m[0][a]].clone(); f = this.vertices[m[0][a + 1]].clone(); y.setY(0).normalize(); f.setY(0).normalize(); for (b = 0; b < u; b++) {
            k = m[b][a]; r = m[b + 1][a]; h = m[b + 1][a + 1]; v = m[b][a +
            1]; var d = y.clone(), w = y.clone(), c = f.clone(), l = f.clone(), x = q[0][a].clone(), z = q[0][a].clone().multiplyScalar(.975), B = q[0][a + 1].clone().multiplyScalar(.975), G = q[0][a + 1].clone(); this.faces.push(new THREE.Face3(k, r, v, [d, w, l])); this.faceVertexUvs[0].push([x, z, G]); this.faces.push(new THREE.Face3(r, h, v, [w.clone(), c, l.clone()])); this.faceVertexUvs[0].push([z.clone(), B, G.clone()])
        } for (b = 0; b < u; b++) k = t[b][a], r = t[b + 1][a], h = t[b + 1][a + 1], v = t[b][a + 1], d = y.clone().negate(), w = y.clone().negate(), f.clone().negate(), l = f.clone().negate(),
        n[0][a].clone(), n[0][a].clone().multiplyScalar(1.05), n[0][a + 1].clone().multiplyScalar(1.05), n[0][a + 1].clone(), this.faces.push(new THREE.Face3(k, v, r, [d, l, w])), this.faceVertexUvs[0].push([p.clone(), p.clone(), p.clone()]), this.faces.push(new THREE.Face3(r, v, h, [w.clone(), l, w.clone()])), this.faceVertexUvs[0].push([p.clone(), p.clone(), p.clone()])
    } if (0 < e) for (a = 0; a < this.o; a++) k = m[0][a], r = m[0][a + 1], e = t[0][a], u = t[0][a + 1], d = new THREE.Vector3(0, 1, 0), w = new THREE.Vector3(0, 1, 0), c = new THREE.Vector3(0, 1, 0), x = q[0][a].clone(),
    z = q[0][a + 1].clone(), y = n[0][a].clone(), f = n[0][a + 1].clone(), this.faces.push(new THREE.Face3(k, r, e, [d, w, c])), this.faceVertexUvs[0].push([x, z, y]), this.faces.push(new THREE.Face3(u, e, r, [d, w, c])), this.faceVertexUvs[0].push([f, y, z]); if (0 < g) for (a = 0; a < this.o; a++) k = m[b][a + 1], r = m[b][a], e = t[b][a + 1], u = t[b][a], d = new THREE.Vector3(0, -1, 0), w = new THREE.Vector3(0, -1, 0), c = new THREE.Vector3(0, -1, 0), q[b][a + 1].clone(), q[b][a].clone(), n[b][a + 1].clone(), n[b][a].clone(), this.faces.push(new THREE.Face3(k, r, u, [d, w, c])), this.faceVertexUvs[0].push([p.clone(),
    p.clone(), p.clone()]), this.faces.push(new THREE.Face3(e, u, k, [d, w, c])), this.faceVertexUvs[0].push([p.clone(), p.clone(), p.clone()]); this.computeFaceNormals()
}; DiscGeometry.prototype = Object.create(THREE.Geometry.prototype); DiscGeometry.prototype.constructor = DiscGeometry;
function R() {
    var e, g, k, a, u = new THREE.Color("darkgray"), b, r, m, q, t, n, p, h; this.B = function (a) { if (p) a(); else { var b = function (b) { t = b; n = new THREE.MeshBasicMaterial({ map: t, side: THREE.FrontSide }); p = !0; a() }; h = new THREE.TextureLoader; h.load("Images/WoodFine0046_3_S512.jpg", function (a) { r = a; m = new THREE.MeshPhongMaterial({ map: r, color: 16764879 }); q = new THREE.MeshPhongMaterial({ map: r, color: 8453888 }); h.load("Images/FloorsMedieval0031_1_S.512.jpg", b) }) } }; this.w = function () { this.X = !1 }; this.w.prototype = {
        g: function () {
            if (!this.X) {
                var a =
                new THREE.CubeGeometry(1, 1, 1, 2, 1, 1); this.F = new THREE.Mesh(a, m); this.F.receiveShadow = !0; b = this.F; e.add(this.F); this.X = !0
            }
        }, render: function (a) { b.scale.copy(new THREE.Vector3(a.a, a.c, a.d)); b.position.x = a.x - 50 + a.a / 2; b.position.y = 15 - a.y - a.c / 2 }
    }; this.C = function () { var a = new THREE.CylinderGeometry(.5, .5, 1, 8, 1, !1), a = new THREE.Mesh(a, m); a.position.copy(b.position); a.castShadow = !0; a.receiveShadow = !0; e.add(a); this.I = a }; this.C.prototype = {
        g: function (a) {
            this.I.scale.copy(new THREE.Vector3(a.a, a.c, a.a)); this.I.position.x =
            a.x - 50 + a.a / 2; this.I.position.y = 15 - a.y - a.c / 2
        }, render: function () { }
    }; this.A = function (a) { this.s = a; a = new DiscGeometry(.5, 1, 1, 24, 1, this.s); a = new THREE.Mesh(a, m); a.castShadow = !0; a.receiveShadow = !0; e.add(a); this.f = a }; this.A.prototype = { g: function (a) { a = new DiscGeometry(a.K / 2, a.a / 2, a.c, 24, 1, this.s); this.f.geometry = a }, render: function (a) { this.f.material = a.selected ? q : m; this.f.position.x = a.x - 50 + a.a / 2; this.f.position.y = 15 - a.y - a.c / 2 } }; var v = !1; this.J = function (b, h) {
        h && (v = !1); if (v) a.setSize(g.width, g.height), k.aspect =
        g.width / g.height, k.updateProjectionMatrix(); else {
            e = new THREE.Scene; g = b; k = new THREE.PerspectiveCamera(25, g.width / g.height, .1, 1E4); a = new THREE.WebGLRenderer({ antialias: !0, canvas: g, devicePixelRatio: 1 }); a.setClearColor(u, 1); a.autoClearColor = !0; a.autoClear = !0; a.shadowMap.enabled = !0; a.shadowMap.type = THREE.PCFSoftShadowMap; t.wrapS = t.wrapT = THREE.RepeatWrapping; t.repeat.set(10, 10); n = new THREE.MeshBasicMaterial({ map: t, side: THREE.DoubleSide }); var c = new THREE.PlaneGeometry(1E3, 1E3, 10, 10), c = new THREE.Mesh(c, n);
            c.position.y = -30; c.rotation.x = Math.PI / 2; e.add(c); e.fog = new THREE.FogExp2(0, .004); c = new THREE.AmbientLight(4210752); e.add(c); c = new THREE.PointLight(16777215, .4, 400); c.position.set(0, 9.5, 190); e.add(c); c = new THREE.SpotLight(16777215, 1); c.position.set(36, 120, 30); c.castShadow = !0; c.shadow.mapSize.width = 1024; c.shadow.mapSize.height = 1024; c.shadow.camera.near = .2; c.shadow.camera.far = 500; c.shadow.camera.fov = 40; e.add(c); cf = 14; c = new THREE.Vector3(1 * cf, 3 * cf, 6 * cf); k.position.copy(c); k.updateProjectionMatrix(); v =
            !0
        }
    }; this.P = function () { }; this.show = function () { var b = new THREE.Vector3(0, -5, 0); k.lookAt(b); k.updateProjectionMatrix(); a.render(e, k); this.controls && this.controls.update() }
}
function S(e) {
    function g(a, b) { this.da = b; this.D = 2 * a / b; this.ea = -this.D / b; this.S = a / 1E6; this.W = 0 } function k(a, b, v, c, e, f) { this.x = a; this.y = b; this.K = v; this.a = c; this.c = e; this.selected = !1; this.j = f; f.g(this) } function a(a, b, v, c, e, f) { this.x = a; this.y = b; this.a = v; this.c = c; this.d = e; this.j = f; f.g(this) } var u, b, r, m, q, t = 1 / 60, n, p, h, v, d, w, c, x, z, y, f, l, B, G, K, E, A, D, L, H = [], I = !0, F = -1, M, J = !1, N; this.B = function (a) { e.B(a) }; this.ka = function (a, c, e, f) { b = a; r = c; n = e; p = f; v = !1; d = !0; x = -1; pause = !1; window.requestAnimationFrame && (J = !0) }; this.resize =
    function () { b && (b.width = r.clientWidth - 10, b.height = .3 * b.width, e.J(b), e.show()) }; var O = !1; this.la = function () {
        B = Math.min(2, 25 / (n + 4)); e.J(b, !O); if (!O) {
            h = 95 / p; var C = 6 / p, v = (h - 2 * C) / 3 + 2 * C, c = (h - C / 2) * n / (n + 1); y = new a(2.5, 25, 95, 3, c + C, new e.w); f = Array(p); l = Array(n); for (var g, d = 0; d < p; d++) g = new P(l, y, B, new e.C), f[d] = g, f[d].setPosition(y.x + h * (d + .5), y.y - B * (n + 1), C, B * (n + 1)), f[d].j.g(f[d]); for (d = 0; d < n; d++) l[d] = new k(0, 0, .5, 1, B, new e.A(2 * Math.PI * Math.random())), 1 == n ? (l[0].K = C, l[0].a = c) : (g = (c - v) / (n - 1), l[d].K = C, l[d].a = v +
            g * d), l[d].j.g(l[d]); for (d = 0; d < p; d++) for (C = 0; C < f[d].b.length; C++) f[d].fa(C); O = !0
        }
    }; this.V = function () { for (var a = 0; a < p; a++) f[a].clear(); for (a = n - 1; 0 <= a; a--) f[0].load(a) }; this.pa = function (a, b) { w = a; c = b; x = f[w].Z(); K = f[w].y - 2 * B - l[x].y; A = 0; E = (new Date).getTime() / 1E3; m = 0; D = new g(K, .5 / z); q = D.l(A) }; this.m = function () { e.P(b.width, b.height); y.i(); for (var a = 0; a < p; a++) f[a].i(); for (a = 0; a < n; a++) l[a].i(); e.show() }; this.O = function (a, b, d, c) {
        u && !J && clearInterval(u); H = a; v = !1; z = b; M = !1; this.U = d; this.T = c; J ? (N = !1, requestAnimationFrame(this.H(this))) :
        u = setInterval(this.H(this), 1E3 * t)
    }; this.ma = function () { b && (this.la(), this.V(), I = !0, F = -1, L = d = !1, this.U(), this.m()) }; this.H = function (a) { return function () { J && !N && requestAnimationFrame(a.H(a)); v || M ? d || M ? (J ? N = !0 : clearInterval(u), a.T()) : a.ja() : (v = !0, a.ma()) } }; this.ja = function () { if (I) { if (L) if (A > .5 / z) L = !1, A = 0, E = (new Date).getTime() / 1E3; else { A = (new Date).getTime() / 1E3 - E; return } F++; F == H.length ? d = !0 : (I = !1, this.pa(H[F].source, H[F].G), this.R()) } else this.R(), I && (L = F + 1 != H.length, A = 0, E = (new Date).getTime() / 1E3) };
    this.R = function () {
        if (!d) {
            l[x].x += m; l[x].y += q; A = (new Date).getTime() / 1E3 - E; if (0 > q) l[x].y < f[w].y - 2 * B ? (l[x].y = f[w].y - 2 * B, A = q = 0, E = (new Date).getTime() / 1E3, G = f[c].h() - f[w].h(), D = new g(G, 1 / z), m = D.l(A)) : q = D.l(A); else if (0 != m) { var a = f[c].h() - l[x].h(); .1 >= (0 < D.D ? a : -a) ? (l[x].x = f[c].h() - l[x].a / 2, A = 0, E = (new Date).getTime() / 1E3, K = (0 == f[c].b.length ? y.y - B : l[f[c].b[f[c].b.length - 1]].y - B) - l[x].y, m = 0, D = new g(K, .5 / z), q = D.l(A)) : m = D.l(A) } else 0 < q ? (a = f[c].height(0) - B, l[x].y > a ? (f[c].load(x), q = 0, I = !0) : q = D.l(A)) : console.log("Wrong");
            this.m()
        }
    }; this.U = function () { console.log("fInit not set") }; this.T = function () { console.log("endfn not set") }; this.Y = function (a) { return f[a].Y() }; this.na = function (a, b) { f[b].load(f[a].Z()) }; this.oa = function () { var a = []; this.V(); for (var b = 0; b < a.length; b++) this.na(a[b].source, a[b].G) }; this.ha = function () { M = !0 }; a.prototype = { i: function () { this.j.render(this) } }; var P = this.ba = function (a, b, d, c) { this.b = []; this.f = a; this.ia = d; this.j = c; c.g(this) }; P.prototype = {
        setPosition: function (a, b, d, c) {
            this.x = a; this.y = b; this.a =
            d; this.c = c; this.qa = b + c
        }, h: function () { return this.x + this.a / 2 }, Y: function () { return 0 == this.b.length ? -1 : this.b[this.b.length - 1] }, i: function () { this.j.render(this) }, fa: function (a) { this.f[this.b[a]].x = this.h() - this.f[this.b[a]].a / 2 }, load: function (a) { this.b.push(a); this.f[a].x = this.h() - this.f[a].a / 2; this.f[a].y = this.qa - this.ia * this.b.length }, Z: function () { return this.b.pop() }, clear: function () { this.b = [] }, height: function (a) { return (0 == this.b.length ? this.y + this.c : this.f[this.b[this.b.length - 1]].y) - a }
    }; k.prototype =
    { h: function () { return this.x + this.a / 2 }, i: function () { this.j.render(this) } }; g.prototype = { l: function (a) { a = this.ga(a); var b = a - this.W; this.W = a; return 0 <= this.D ? Math.max(b, this.S) : Math.min(b, this.S) }, ga: function (a) { a = Math.min(a, this.da); return (this.D + .5 * this.ea * a) * a } }; this.ca = { aa: 0, ta: 1 }; this.N = function (a, b, c, d) { this.ra = a; this.f = b; this.source = c; this.G = d }; this.N.prototype.toString = function () { return " " + this.ra + "," + this.f + "," + this.source + "," + this.G }
}
(function () {
    function e() { p = h.checked; m = h.disabled = !0; q = t = !1; var b = $("#canvas")[0], d = $('<canvas id="canvas" height="' + b.height + '" width="' + b.width + '">'); b.removeNode ? b.removeNode(!0) : $("#canvas")[0].remove(); $("#precanvas"); $("#precanvas").after(d); a() } function g() {
        if (q) t = !0, b.ha(); else {
            var a = parseFloat($("#MainContent_SpeedFactor").val()); isNaN(a) && (a = 1); a = Math.min(Math.max(a, .1), 50); $("#MainContent_SpeedFactor").attr("value", a.toString()); m = !1; q = !0; t = !1; n.value = "Cancel"; h && (h.disabled = !0); b.O(r,
            a, function () { }, k)
        }
    } function k() { t && (b.oa(), t = !1); q = !1; n.value = "Show Solution"; window.WebGLRenderingContext && h && (h.disabled = !1); m = !0; b.m() } function a() { for (var a = $("#MainContent_Moves").val().split(","), d = 0; d < a.length; d++) a[d] = parseInt(a[d]); var e = a[0], c = a[1]; m = !0; b = new S(p ? new R : new Q); for (var d = 2, g = -1; d < a.length; d += 2) r[++g] = new b.N(b.ca.aa, -1, a[d], a[d + 1]); b.B(function () { b.ka($("#canvas")[0], $("#MainContent_Panel2")[0], e, c); b.O([], 1, function () { }, function () { b.resize(); b.m() }); h.disabled = !1 }) } function u() {
        b.resize();
        m && b.m()
    } document.addEventListener("keypress", function (a) { 13 == a.keyCode && (a.preventDefault(), a.stopPropagation()) }, !0); var b, r = [], m, q, t, n, p = !1, h; $(document).ready(function () {
        (h = document.getElementById("MainContent_cb3d")) ? window.WebGLRenderingContext ? (h.disabled = !1, p = h.checked, h.onchange = e) : (h.disabled = !0, h.style.visibility = "hidden", document.getElementById("cb3dl").style.visibility = "hidden", p = !1) : p = !1; $("#showSolution").click(g); n = document.getElementById("showSolution"); m = !0; q = t = !1; a(); window.onresize =
        u; var b = document.getElementById("warning"); if (b) { var d = navigator.userAgent.toLowerCase(); b.style.display = 0 <= d.indexOf("android") && 0 > d.indexOf("firefox") ? "inline" : "none" }
    })
})();
