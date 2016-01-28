(ns internal.node-type-test
  (:require [clojure.test :refer :all]
            [dynamo.graph :as g]
            [internal.graph.types :as gt]
            [internal.node :as in]
            [support.test-support :refer [with-clean-system tx-nodes]]))

(g/defnode SuperType
  (property super-prop g/Str)
  (input super-in g/Str)
  (output super-out g/Str (g/fnk [super-prop] super-prop)))

(g/defnode SubType
  (inherits SuperType)
  (property sub-prop g/Str)
  (input sub-in g/Str)
  (output sub-out g/Str (g/fnk [sub-prop] sub-prop)))

(deftest type-fns []
  (is (= #{:super-out :sub-out :_properties :_declared-properties} (set (keys (g/declared-outputs SubType)))))
  (is (= #{:super-in :sub-in} (set (keys (g/declared-inputs SubType)))))
  (is (= #{:super-prop :sub-prop :_output-jammers :_node-id} (set (keys (g/declared-properties SubType))))))

(deftest input-prop-collision []
  (is (thrown? AssertionError (g/defnode InputPropertyCollision
                                (input value g/Str)
                                (property value g/Str)))))
